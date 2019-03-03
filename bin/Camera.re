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

let create = (~origin: Point3f.t, ~bottomLeft: Vec3f.t, ~horizontal: Vec3f.t, ~vertical: Vec3f.t, ~traceParams: traceParams) =>
  {
    origin,
    bottomLeft,
    horizontal,
    vertical,
    traceParams
  };