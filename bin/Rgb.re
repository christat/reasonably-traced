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