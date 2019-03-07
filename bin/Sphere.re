open Math;

type t = {
  position: Point3f.t,
  radius: float,
  material: Material.t
};

let getRecord = (~ray: Ray.t, ~min_t: float, ~max_t: float, ~sphere: t, ~quadraticRoot: float): option(Material.record) => {
  switch(quadraticRoot > min_t && quadraticRoot < max_t) {
  | true => {
      let { position, radius, material }: t = sphere;
      let point = Ray.pointAlong(~t=quadraticRoot, ray);
      let normal = Vec3f.sub(point, position) |> Vec3f.divConst(radius);
      let record: Material.record = { t: quadraticRoot, point: point, normal, material };
      Some(record);
    };
  | false => None
  };
};

/*
  Checks ray-sphere intersection, returning a Record if hit.
  Computed by solving for p(t) using ray and sphere equations:
  ray -> p(t) = A + t*B 
  sphere -> (x-cx)*(x-cx) + (y-cy)*(y-cy) + (z-cz)*(z-cz)= R*R 
  t*t*dot(B, B) + 2*t*dot(B, A-C) + dot(A-C, A-C) - R*R = 0
*/
let intersection = (~ray: Ray.t, ~min_t: float, ~max_t: float, sphere: t): option(Material.record) => {
  let distance = Vec3f.sub(ray.origin, sphere.position);
  let a = Vec3f.dot(ray.direction, ray.direction);
  let b = 2.0 *. Vec3f.dot(distance, ray.direction);
  let c = Vec3f.dot(distance, distance) -. (sphere.radius *. sphere.radius);
  let discriminant = (b *. b) -. (4.0 *. a *. c);

  switch (discriminant > 0.0) {
  | false => None
  | true => {
      let quadraticRoot = (-1.0 *. b -. sqrt(discriminant)) /. (2.0 *. a);
      let record = getRecord(~ray, ~min_t, ~max_t, ~sphere, ~quadraticRoot);
      switch (record) {
      | Some(r) => Some(r)
      | None => {
          let quadraticRoot = (-1.0 *. b +. sqrt(discriminant)) /. (2.0 *. a);
          getRecord(~ray, ~min_t, ~max_t, ~sphere, ~quadraticRoot);
        };
      };
    };
  };
};