open Math;

type traceParams = {
  height: int,
  width: int,
  samples: int
};

type t = {
  origin: Point3f.t,
  bottomLeft: Vec3f.t,
  horizontal: Vec3f.t,
  vertical: Vec3f.t,
  traceParams: traceParams
};

let create = (~origin: Point3f.t, ~bottomLeft: Vec3f.t, ~horizontal: Vec3f.t, ~vertical: Vec3f.t, ~traceParams: traceParams): t => {
  origin,
  bottomLeft,
  horizontal,
  vertical,
  traceParams
};

let getRay = (~u: float, ~v: float, camera: t): Ray.t => {
  let pointOnFrustumPlane = Vec3f.mulConst(u, camera.horizontal)
    |> Vec3f.add(Vec3f.mulConst(v, camera.vertical))
    |> Vec3f.add(camera.bottomLeft);
  {
    origin: camera.origin,
    direction: Vec3f.sub(pointOnFrustumPlane, camera.origin)
  };
};