open Math;

let rec randomPointInUnitSphere = (): Point3f.t => {
  let r = (Random.float(1.0), Random.float(1.0), Random.float(1.0)) |> Vec3f.mulConst(2.0);
  let point = Vec3f.sub(r, (1.0, 1.0, 1.0));
  switch (Vec3f.lenSquared(point) >= 1.0) {
  | true => randomPointInUnitSphere()
  | false => point
  };
};

let rec randomPointInUnitDisk = (): Point3f.t => {
  let r = (Random.float(1.0), Random.float(1.0), 0.0);
  let point = Vec3f.sub(Vec3f.mulConst(2.0, r), (1.0, 1.0, 0.0));
  switch (Vec3f.dot(point, point) >= 1.0) {
  | true => randomPointInUnitDisk()
  | false => point
  };
};

let reflect = (~vector: Vec3f.t, ~normal: Vec3f.t): Vec3f.t => {
  let k = 2.0 *. Vec3f.dot(vector, normal);
  Vec3f.mulConst(k, normal) |> Vec3f.sub(vector);
};

let refract = (~vector: Vec3f.t, ~normal: Vec3f.t, niOverNt: float): option(Vec3f.t) => {
  let nv = Vec3f.normalized(vector);
  let dt = Vec3f.dot(nv, normal);
  let discriminant = 1.0 -. niOverNt *. niOverNt *. (1.0 -. dt *. dt);
  switch (discriminant > 0.0) {
  | false => None
  | true => {
      let t1 =
        Vec3f.mulConst(dt, normal)
        |> Vec3f.sub(nv)
        |> Vec3f.mulConst(niOverNt);

      let t2 = Vec3f.mulConst(sqrt(discriminant), normal);
      Some(Vec3f.sub(t1, t2));
   };
  };
};

let schlick = (~cosine: float, ~refractivity: float): float => {
  let r0 = ((1.0 -. refractivity) /. (1.0 +. refractivity)) ** 2.0;
  r0 +. (1.0 -. r0) *. ((1.0 -. cosine) ** 5.0);
}

let minMax = (~minimum: float=0.0, ~maximum: float=1.0, value: float) => max(minimum, value) |> min(maximum);