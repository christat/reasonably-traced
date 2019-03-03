type t = {
  camera: Camera.t,
  scene: Scene.t
};


let chapter4 = ({ width, height, samples }: Camera.traceParams): t => {
  let camera = Camera.create(
    ~origin=(0.0, 0.0, 0.0),
    ~bottomLeft=(-2.0, -1.0, -1.0),
    ~horizontal=(4.0, 0.0, 0.0),
    ~vertical=(0.0, 2.0, 0.0),
    ~traceParams={
      width,
      height,
      samples
    });

  let sphere: Sphere.t = {
    position: (0.0, 0.0, -1.0), 
    radius: 0.5
  };
  
  { camera, scene: [Sphere(sphere)] };
}

let chapter5 = ({ width, height, samples }: Camera.traceParams): t => {
  let camera = Camera.create(
    ~origin=(0.0, 0.0, 0.0),
    ~bottomLeft=(-2.0, -1.0, -1.0),
    ~horizontal=(4.0, 0.0, 0.0),
    ~vertical=(0.0, 2.0, 0.0),
    ~traceParams={
      width,
      height,
      samples
    });

  let sphere: Sphere.t = {
    position: (0.0, 0.0, -1.0), 
    radius: 0.5
  };

  let backgroundSphere: Sphere.t = {
    position: (0.0, -100.5, -1.0),
    radius: 100.0
  };
  
  { camera, scene: [Sphere(sphere), Sphere(backgroundSphere)] };
}