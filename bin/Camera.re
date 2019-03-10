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
  basis: basis,
  lensRadius: float,
  traceParams: traceParams
};

let defaultParams: traceParams = {
  width: 200,
  height: 100,
  samples: 100
};

let create = (~origin: Point3f.t, ~direction: Vec3f.t, ~vFov: float, ~focusDistance: float=0.0, ~aperture: float=0.0, ~traceParams: traceParams): t => {
  let aspect = float(traceParams.width) /. float(traceParams.height);
  let theta = vFov *. Math.pi /. 180.0
  let halfHeight = tan(theta /. 2.0);
  let halfWidth = aspect *. halfHeight;
  let w = Vec3f.sub(origin, direction) |> Vec3f.normalized;
  let u = Vec3f.cross((0.0, 1.0, 0.0), w) |> Vec3f.normalized;
  let v = Vec3f.cross(w, u);
  let halfHeightV = Vec3f.mulConst(halfHeight *. focusDistance, v);
  let halfWidthU = Vec3f.mulConst(halfWidth *. focusDistance, u);
  {
    origin,
    bottomLeft: Vec3f.sub(Vec3f.sub(Vec3f.sub(origin, halfWidthU), halfHeightV), Vec3f.mulConst(focusDistance, w)),
    horizontal: Vec3f.mulConst(2.0 *. halfWidth *. focusDistance, u),
    vertical: Vec3f.mulConst(2.0 *. halfHeight *. focusDistance, v),
    basis: { u, v, w },
    lensRadius: aperture /. 2.0,
    traceParams
  };
};

let getRay = (~i: float, ~j: float, camera: t): Ray.t => {
  let (x, y, _) = Utils.randomPointInUnitDisk() |> Vec3f.mulConst(camera.lensRadius);
  let pointOnFrustumPlane = Vec3f.mulConst(i, camera.horizontal)
    |> Vec3f.add(Vec3f.mulConst(j, camera.vertical))
    |> Vec3f.add(camera.bottomLeft);
  let offset = Vec3f.mulConst(x, camera.basis.u) |> Vec3f.add(Vec3f.mulConst(y, camera.basis.v));
  {
    origin: Vec3f.add(camera.origin, offset),
    direction: Vec3f.sub(Vec3f.sub(pointOnFrustumPlane, camera.origin), offset)
  };
};