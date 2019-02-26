
module Rgb = {
  type t = Math.vec3(int);
  let r = (rgb: t) => {
    let (r, _, _) = rgb;
    r;
  };
  let g = (rgb: t) => {
    let (_, g, _) = rgb;
    g;
  };
  let b = (rgb: t) => {
    let (_, _, b) = rgb;
    b;
  };
  let print = (rgb: t) => {
    let (r, g, b) = rgb;
    print_endline(string_of_int(r) ++ " " ++ string_of_int(g) ++ " " ++ string_of_int(b));
  };
}; 