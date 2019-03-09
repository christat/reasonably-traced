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

let defaultParams: traceParams = {
  width: 200,
  height: 100,
  samples: 100
};

let create = (~origin: Point3f.t, ~bottomLeft: Vec3f.t, ~horizontal: Vec3f.t, ~vertical: Vec3f.t, ~traceParams: traceParams): t => {
  origin,
  bottomLeft,
  horizontal,
  vertical,
  traceParams
};

let createDynamic = (~origin: Point3f.t, ~direction: Vec3f.t, ~vFov: float, ~traceParams: traceParams): t => {
  let aspect = float(traceParams.width) /. float(traceParams.height);
  let theta = vFov *. Math.pi /. 180.0
  let halfHeight = tan(theta /. 2.0);
  let halfWidth = aspect *. halfHeight;
  let w = Vec3f.sub(origin, direction) |> Vec3f.normalized;
  let u = Vec3f.cross((0.0, 1.0, 0.0), w) |> Vec3f.normalized;
  let v = Vec3f.cross(w, u);
  let halfHeightV = Vec3f.mulConst(halfHeight, v);
  let halfWidthU = Vec3f.mulConst(halfWidth, u);
  {
    origin,
    bottomLeft: Vec3f.sub(Vec3f.sub(Vec3f.sub(origin, halfWidthU), halfHeightV), w),
    horizontal: Vec3f.mulConst(2.0 *. halfWidth, u),
    vertical: Vec3f.mulConst(2.0 *. halfHeight, v),
    traceParams
  };
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