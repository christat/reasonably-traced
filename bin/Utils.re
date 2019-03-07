open Math;

let rec randomPointInUnitSphere = (): Point3f.t => {
  let r = (Random.float(1.0), Random.float(1.0), Random.float(1.0)) |> Vec3f.mulConst(2.0);
  let point = Vec3f.sub(r, (1.0, 1.0, 1.0));
  switch (Vec3f.lenSquared(point) >= 1.0) {
  | true => randomPointInUnitSphere()
  | false => point
  };
};

let reflect = (~vector: Vec3f.t, ~normal: Vec3f.t): Vec3f.t => {
  let k = 2.0 *. Vec3f.dot(vector, normal);
  Vec3f.mulConst(k, normal) |> Vec3f.sub(vector);
};

let minMax = (~minimum: float=0.0, ~maximum: float=1.0, value: float) => max(minimum, value) |> min(maximum);