open Math;

let rec trace = (~x: int, ~y: int, ~camera: Camera.t, ~scene: Scene.t, buffer: Buffer.t) => {
  let { width, height, _ }: Camera.traceParams = camera.traceParams;
  let u = floatOfIntDiv(x, width);
  let v = floatOfIntDiv(y, height);

  let ray: Ray.t = {
    origin: camera.origin,
    direction: 
      Vec3f.mulConst(u, camera.horizontal)
      |> Vec3f.add(Vec3f.mulConst(v, camera.vertical))
      |> Vec3f.add(camera.bottomLeft)
  };

  let updatedBuffer =
    Scene.intersection(~ray, scene)
    /* convert rgb from [0, 1] float scale to [0, 255] int scale */
    |> Vec3f.mulConst(255.99)
    |> Vec3f.toInt
    |> Buffer.append(buffer);

  switch (x, y) {
  | (x, _) when x + 1 < width => trace(~x=x + 1, ~y=y, ~camera, ~scene, updatedBuffer)
  | (_, y) when y - 1 >= 0 => trace(~x=0, ~y=y - 1, ~camera, ~scene, updatedBuffer)  
  | _ => Buffer.print(~width, ~height, buffer)
  };
};