open Math;

type prop = Sphere | Rectangle | Plane | Obj;
type scene = List(prop);
type t = {
  origin: Point3f.t,
  direction: Vec3f.t,
  scene: scene,
  /*buffer: Array(RGB.t)*/
};

let create = (~origin=Point3f.t, ~direction=Vec3f.t, ~scene=scene) =>
  {
    origin,
    direction,
    scene
  };