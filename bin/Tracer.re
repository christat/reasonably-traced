open Math;

let rec sample = (~index: int=0, ~x: int, ~y: int, ~camera: Camera.t, ~scene: Scene.t, color: Vec3f.t): Rgb.t => {
  let { width, height, samples }: Camera.traceParams = camera.traceParams;
  switch (index < samples) {
  | true => {
      let u = (float(x) +. Random.float(1.0)) /. float(width);
      let v = (float(y) +. Random.float(1.0)) /. float(height);
      let ray = Camera.getRay(~u, ~v, camera);
      let updatedColor = Scene.intersection(~ray, scene) |> Vec3f.add(color);
      sample(~index=index+1, ~x, ~y, ~camera, ~scene, updatedColor);
    };
  | false => 
      Vec3f.divConst(float(samples), color)
      /* convert rgb from [0, 1] float scale to [0, 255] int scale */
      |> Vec3f.mulConst(255.99)
      |> Vec3f.toInt
  };
};

let rec trace = (~x: int, ~y: int, ~camera: Camera.t, ~scene: Scene.t, buffer: Buffer.t): unit => {
  let color = sample(~x, ~y, ~camera, ~scene, (0.0, 0.0, 0.0));
  let updatedBuffer = Buffer.append(buffer, color);

  let { width, height, _ }: Camera.traceParams = camera.traceParams;
  switch (x, y) {
  | (x, _) when x + 1 < width => trace(~x=x + 1, ~y, ~camera, ~scene, updatedBuffer)
  | (_, y) when y - 1 >= 0 => trace(~x=0, ~y=y - 1, ~camera, ~scene, updatedBuffer)  
  | _ => Buffer.print(~width, ~height, buffer)
  };
};