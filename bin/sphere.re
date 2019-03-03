open Math;

type t = {
  position: Point3f.t,
  radius: float
};

/* ray -> p(t) = A + t*B */
/* sphere -> (x-cx)*(x-cx) + (y-cy)*(y-cy) + (z-cz)*(z-cz)= R*R */
/* t*t*dot(B, B) + 2*t*dot(B, A-C) + dot(A-C, A-C) - R*R = 0 */
let intersects = (ray: Ray.t, sphere: t) => {
  let distance = Vec3f.sub(ray.origin, sphere.position);
  let a = Vec3f.dot(ray.direction, ray.direction);
  let b = 2.0 *. Vec3f.dot(distance, ray.direction);
  let c = Vec3f.dot(distance, distance) -. (sphere.radius *. sphere.radius);
  let discriminant = (b *. b) -. (4.0 *. a *. c);
  discriminant > 0.0;
};