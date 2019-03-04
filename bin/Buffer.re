type t = list(Rgb.t);

let print = (~width: int, ~height: int, buffer: t): unit => {
  print_string("P3\n" ++ string_of_int(width) ++ " " ++ string_of_int(height) ++ "\n255\n");
  List.map(rgb => Rgb.print(rgb), buffer |> List.rev) |> ignore;
};

/* TODO export directly to .ppm file */

let append = (buffer: t, value: Rgb.t): t => [value, ...buffer];

