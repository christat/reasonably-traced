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
  let (_, y, _) = Vec3f.normalized(ray.direction);
  let t: float = 0.5 *. (y +. 1.0);
  let (r, g, b) =
    Vec3f.mulConst((1.0 -. t), (1.0, 1.0, 1.0))
    |> Vec3f.add(Vec3f.mulConst(t, (0.5, 0.7, 1.0)));
  (int_of_float(r *. 255.99), int_of_float(g *. 255.99), int_of_float(b *. 255.99));
};

let printBuffer = (~width: int, ~height: int, buffer: list(Rgb.t)) => {
  print_string("P3\n" ++ string_of_int(width) ++ " " ++ string_of_int(height) ++ "\n255\n");
  List.map(rgb => Rgb.print(rgb), buffer |> List.rev);
};

let rec fillBuffer = (~x: int, ~y: int, ~width: int, ~height: int, ~samples: int, buffer: list(Rgb.t)) => {
  let (u, v): (float, float) = (floatOfIntDiv(x, width), floatOfIntDiv(y, height));
  let ray: Ray.t = {
    origin: Camera.origin,
    direction: 
      Vec3f.mulConst(u, Camera.horizontal)
      |> Vec3f.add(Vec3f.mulConst(v, Camera.vertical))
      |> Vec3f.add(Camera.bottomLeft)
  };

  let updatedBuffer = [computeColor(ray), ...buffer];
  switch (x, y) {
  | (x, _) when x + 1 < width => fillBuffer(~x=x + 1, ~y=y, ~width=width, ~height=height, ~samples=samples, updatedBuffer)
  | (_, y) when y - 1 >= 0 => fillBuffer(~x=0, ~y=y - 1, ~width=width, ~height=height, ~samples=samples, updatedBuffer)  
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
