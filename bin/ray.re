open Math;

type t = {
  origin: Point3f.t, 
  direction: Vec3f.t
};

let pointAlongRay = (~t: float, ray: t) =>
  Vec3f.mulConst(t, ray.direction) |> Vec3f.add(ray.origin);
