open Math;

type traceable('s, 'o) = Sphere('s) | Other('o);
type entityTypes = traceable(Sphere.t, unit);

type t = list(entityTypes);

let rec intersection = (~ray: Ray.t, ~min_t: float=0.001, ~max_t: float=infinity, ~record: option(Record.t)=None, items: t): option(Record.t) =>
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

let rec computeColor = (~ray: Ray.t, scene: t): Vec3f.t => {
  switch (intersection(~ray, scene)) {
  | Some(record) => {
      let { point, normal, _ }: Record.t = record;
      let target = Vec3f.add(point, normal) |> Vec3f.add(Utils.randomPointInUnitSphere());
      let bounce: Ray.t = { origin: point, direction: Vec3f.sub(target, point) };
      Vec3f.mulConst(0.5, computeColor(~ray=bounce, scene));
    };
  | None => {
      let (_, y, _) = Vec3f.normalized(ray.direction);
      let t: float = 0.5 *. (y +. 1.0);
      Vec3f.mulConst((1.0 -. t), (1.0, 1.0, 1.0))
      |> Vec3f.add(Vec3f.mulConst(t, (0.5, 0.7, 1.0)));
    };
  };
};