open Math;

type material('l, 'm, 'd) =
  Lambertian('l)
  | Metal('m)
  | Dielectric('d);


type lambertian = {
  albedo: Vec3f.t
};

type metal = {
  albedo: Vec3f.t,
  fuzz: float
};

type dielectric = {
  refractivity: float
};

type t =
  material(
    lambertian,
    metal,
    dielectric
  );

type record = {
  t: float,
  point: Point3f.t,
  normal: Vec3f.t,
  material: t
};

type scatter = {
  scattered: Ray.t,
  attenuation: Vec3f.t
};

let scatterLambertian = (~record: record, lambertian: lambertian): option(scatter) => {
  let target = Vec3f.add(record.point, record.normal) |> Vec3f.add(Utils.randomPointInUnitSphere());
  let scattered: Ray.t = { origin: record.point, direction: Vec3f.sub(target, record.point) };
  Some({ scattered, attenuation: lambertian.albedo });
};

let scatterMetal = (~ray: Ray.t, ~record: record, metal: metal): option(scatter)  => {
  let reflected = Utils.reflect(~vector=Vec3f.normalized(ray.direction), ~normal=record.normal);
  switch (Vec3f.dot(reflected, record.normal) > 0.0) {
  | true => Some({
      scattered: {
        origin: record.point,
        direction: Vec3f.add(reflected, Vec3f.mulConst(Utils.minMax(metal.fuzz), Utils.randomPointInUnitSphere()))
      },
      attenuation: metal.albedo
    })
  | false => None
  };
};

let scatterDielectric = (~ray: Ray.t, ~record: record, dielectric: dielectric): option(scatter) => {
  let { direction, _ }: Ray.t = ray;
  let { normal, point, _ }: record = record;
  let { refractivity }: dielectric = dielectric;

  let rayObjectDot = Vec3f.dot(direction, normal);
  let (outwardNormal, niOverNt, cosine) = switch (rayObjectDot > 0.0) {
    | true => {
        let cosine = refractivity *. rayObjectDot /. Vec3f.len(direction);
        (Vec3f.mulConst(-1.0, normal), refractivity, cosine);
      };
    | false => (normal, 1.0 /. refractivity, -1.0 *. rayObjectDot /. Vec3f.len(direction))
  };

  let reflected = Utils.reflect(~vector=direction, ~normal);
  let refracted = Utils.refract(~vector=direction, ~normal=outwardNormal, niOverNt);

  let scattered: Ray.t = switch (refracted) {
  | None => { origin: point, direction: reflected }
  | Some(r) =>
      switch (Random.float(1.0) < Utils.schlick(~cosine, ~refractivity=dielectric.refractivity)) {
      | true => { origin: point, direction: reflected }
      | false => { origin: point, direction: r }
      };
  };

  Some({ scattered, attenuation: (1.0, 1.0, 1.0) });
};

let scatter = (~ray: Ray.t, ~record: record, material: t): option(scatter) =>
  switch material {
  | Lambertian(l) => scatterLambertian(~record, l)
  | Metal(m) => scatterMetal(~ray, ~record, m)
  | Dielectric(d) => scatterDielectric(~ray, ~record, d)
  };
