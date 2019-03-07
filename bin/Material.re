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
  albedo: Vec3f.t
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

let scatterDielectric = (): option(scatter) => {
  None
};

let scatter = (~ray: Ray.t, ~record: record, material: t): option(scatter) =>
  switch material {
  | Lambertian(l) => scatterLambertian(~record, l)
  | Metal(m) => scatterMetal(~ray, ~record, m)
  | _ => scatterDielectric()
  };

