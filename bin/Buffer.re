type t = list(Rgb.t);

let writeToFile =(~width: int, ~height: int, buffer: t): unit => {
  let header = "P3\n" ++ string_of_int(width) ++ " " ++ string_of_int(height) ++ "\n255\n";
  let file = open_out("reasonably_traced.ppm");
  output_string(file, header);
  List.iter(
    color => {
      let (red, green, blue): Rgb.t = color;
      let r = string_of_int(red);
      let g = string_of_int(green);
      let b = string_of_int(blue);
      output_string(file, r ++ " " ++ g ++ " " ++ b ++ "\n");
    },
    List.rev(buffer)
  );
  close_out(file);
}

let append = (buffer: t, value: Rgb.t): t => [value, ...buffer];

