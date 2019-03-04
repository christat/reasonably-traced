open Math;

type traceable('s, 'o) = Sphere('s) | Other('o);
type entityTypes = traceable(Sphere.t, unit);

type t = list(entityTypes);

let computeColor = (record: Record.t): Vec3f.t =>
  Vec3f.addConst(1.0, record.normal)
  |> Vec3f.mulConst(0.5);

let computeBackgroundColor = (ray: Ray.t): Vec3f.t => {
  let (_, y, _) = Vec3f.normalized(ray.direction);
  let t: float = 0.5 *. (y +. 1.0);
  Vec3f.mulConst((1.0 -. t), (1.0, 1.0, 1.0))
  |> Vec3f.add(Vec3f.mulConst(t, (0.5, 0.7, 1.0)));
};

let rec intersection = (~ray: Ray.t, ~min_t: float=0.0, ~max_t: float=infinity, ~record: option(Record.t)=None, items: t): Vec3f.t =>
  switch (items) {
  | [] =>
    switch record {
    | Some(r) => computeColor(r)
    | None => computeBackgroundColor(ray)
    };
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