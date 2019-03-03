type vec3('t) = ('t, 't, 't);

let floatOfIntDiv = (dividend: int, divisor: int) => float_of_int(dividend) /. float_of_int(divisor);

module Vec3f = {
  type t = vec3(float);

  let x = (vec: t) => {
    let (x, _, _) = vec;
    x;
  };

  let y = (vec: t) => {
    let (_, y, _) = vec;
    y;
  };

  let z = (vec: t) => {
    let (_, _, z) = vec;
    z;
  };

  let add = (a: t, b: t) => {
    let (ax, ay, az) = a;
    let (bx, by, bz) = b;
    (ax +. bx, ay +. by, az +. bz);
  };

  let sub = (a: t, b: t) => {
    let (ax, ay, az) = a;
    let (bx, by, bz) = b;
    (ax -. bx, ay -. by, az -. bz);
  };

  let mul = (a: t, b: t) => {
    let (ax, ay, az) = a;
    let (bx, by, bz) = b;
    (ax *. bx, ay *. by, az *. bz);
  };

  let div = (a: t, b: t) => {
    let (ax, ay, az) = a;
    let (bx, by, bz) = b;
    (ax /. bx, ay /. by, az /. bz);
  };

  let addConst = (c: float, v: t) => {
    let (x, y, z) = v;
    (x +. c, y +. c, z +. c);
  };

  let mulConst = (c: float, v: t) => {
    let (x, y, z) = v;
    (x *. c, y *. c, z *. c);
  };

  let divConst = (c: float, v: t) => {
    let (x, y, z) = v;
    (x /. c, y /. c, z /. c);
  }

  let lenSquared = (v: t) => {
    let (x, y, z) = v;
    x*.x +. y*.y +. z*.z;
  };

  let len = (v: t) => lenSquared(v) |> sqrt;

  let normalized = (v: t) => {
    let len = len(v);
    let (x, y, z) = v;
    (x /. len, y /. len, z /. len);
  };

  let dot = (a: t, b: t) => {
    let (ax, ay, az) = a;
    let (bx, by, bz) = b;
    ax*.bx +. ay*.by +. az*.bz;
  };

  let cross = (a: t, b: t) => {
    let (ax, ay, az) = a;
    let (bx, by, bz) = b;
    let x = ay*.bz -. az*.by;
    let y = ax*.bz -. az*.bx;
    let z = ax*.by -. ay*.bx;
    (x, y, z);
  };

  let toInt = (vec: t) => {
    let (x, y, z) = vec;
    (int_of_float(x), int_of_float(y), int_of_float(z));
  }
}

module Point3f = Vec3f;
