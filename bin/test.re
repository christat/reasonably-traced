open Math;
open Color;

module Default = {
  let width: int = 200;
  let height: int = 100;
  let samples: int = 10;
};

module Camera = {
  let bottomLeft: Point3f.t = (-2.0, -1.0, -1.0);
  let horizontal: Vec3f.t = (4.0, 0.0, 0.0);
  let vertical: Vec3f.t = (0.0, 2.0, 0.0);
  let origin: Point3f.t = (0.0, 0.0, 0.0);
};

let computeColor = (ray: Ray.t) => {
  let unitDirection = Vec3f.normalized(ray.direction);
  let t: float = 0.5 *. (Vec3f.y(unitDirection) +. 1.0);
  Vec3f.addConst(~c=1.0 -. t, (1.0, 1.0, 1.0)) |> Vec3f.add(Vec3f.addConst(~c=t, (0.5, 0.7, 1.0)));
};

let printBuffer = (~width: int, ~height: int, buffer: list(Rgb.t)) => {
  print_string("P3\n" ++ string_of_int(width) ++ " " ++ string_of_int(height) ++ "\n255\n");
  List.map(rgb => Rgb.print(rgb), buffer |> List.rev);
};

let rec fillBuffer = (~x: int, ~y: int, ~width: int, ~height: int, ~samples: int, buffer: list(Rgb.t)) => {
  let rgb = (255 * x / width, 255 * y / height, 52);
  let nextBuffer = [rgb, ...buffer];
  switch((x, y)) {
  | (x, _) when x + 1 < width => fillBuffer(~x=x + 1, ~y=y, ~width=width, ~height=height, ~samples=samples, nextBuffer)
  | (_, y) when y - 1 >= 0 => fillBuffer(~x=0, ~y=y - 1, ~width=width, ~height=height, ~samples=samples, nextBuffer)  
  | _ => printBuffer(~width=width, ~height=height, buffer)
  };
};

let () = {
  let (width, height, samples) = 
    switch (Sys.argv) {
    | [| _, "--width", w, "--height", h, "--samples", s |] => (int_of_string(w), int_of_string(h), int_of_string(s))
    | _ => (Default.width, Default.height, Default.samples)
    };

  fillBuffer(~x=0, ~y=height, ~width=width, ~height=height, ~samples=samples, []);
  ();
};
