open Math;

type traceable('s, 'o) = Sphere('s) | Other('o);
type entityTypes = traceable(Sphere.t, unit);

type t = list(entityTypes);

let rec intersection = (~ray: Ray.t, ~min_t: float=0.001, ~max_t: float=infinity, ~record: option(Material.record)=None, items: t): option(Material.record) =>
  switch items {
  | [] => record
  | [item, ...restItems] =>
      switch item {
      | Sphere(s) =>
          switch (Sphere.intersection(~ray, ~min_t, ~max_t, s)) {
          | Some(r) => intersection(~ray, ~min_t, ~max_t=r.t, ~record=Some(r), restItems)
          | None => intersection(~ray, ~min_t, ~max_t, ~record, restItems)
          };
      | _ => intersection(~ray, ~min_t, ~max_t, ~record, restItems)
      };
  };

let rec computeScatteredColor = (~ray: Ray.t, ~depth: int=0, ~scene: t, record: Material.record): Vec3f.t =>
switch (Material.scatter(~ray, ~record, record.material)) {
| Some(s) => Vec3f.mul(s.attenuation, computeColor(~ray=s.scattered, ~depth=depth+1, scene))
| None => (0.0, 0.0, 0.0)
}
and computeColor = (~ray: Ray.t, ~depth: int=0, scene: t): Vec3f.t => {
  switch (intersection(~ray, scene)) {
  | Some(record) => switch (depth >= 50) {
    | true => (0.0, 0.0, 0.0)
    | false => computeScatteredColor(~ray, ~depth, ~scene, record)
    };
  | None => {
      let (_, y, _) = Vec3f.normalized(ray.direction);
      let t: float = 0.5 *. (y +. 1.0);
      Vec3f.mulConst((1.0 -. t), (1.0, 1.0, 1.0))
      |> Vec3f.add(Vec3f.mulConst(t, (0.5, 0.7, 1.0)));
    };
  };
};