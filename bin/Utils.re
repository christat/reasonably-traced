open Math;

let rec randomPointInUnitSphere = () => {
  let r = (Random.float(1.0), Random.float(1.0), Random.float(1.0)) |> Vec3f.mulConst(2.0);
  let point = Vec3f.sub(r, (1.0, 1.0, 1.0));
  switch (Vec3f.lenSquared(point) >= 1.0) {
  | true => randomPointInUnitSphere()
  | false => point
  };
};