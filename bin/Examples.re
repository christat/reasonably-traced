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
    radius: 0.5,
    material: Lambertian({ albedo: (1.0, 0.0, 0.0) })
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
    radius: 0.5,
    material: Lambertian({ albedo: (0.5, 0.5, 0.5) })
  };

  let backgroundSphere: Sphere.t = {
    position: (0.0, -100.5, -1.0),
    radius: 100.0,
    material: Lambertian({ albedo: (0.5, 0.5, 0.5) })
  };
  
  { camera, scene: [Sphere(sphere), Sphere(backgroundSphere)] };
}

let chapter8 = ({ width, height, samples }: Camera.traceParams): t => {
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
    radius: 0.5,
    material: Lambertian({ albedo: (0.8, 0.3, 0.3) })
  };

  let backgroundSphere: Sphere.t = {
    position: (0.0, -100.5, -1.0),
    radius: 100.0,
    material: Lambertian({ albedo: (0.8, 0.8, 0.0) })
  };

  let rightSphere: Sphere.t = {
    position: (1.0, 0.0, -1.0), 
    radius: 0.5,
    material: Metal({ albedo: (0.8, 0.6, 0.2), fuzz: 1.0 })
  };

  let leftSphere: Sphere.t = {
    position: (-1.0, 0.0, -1.0), 
    radius: 0.5,
    material: Metal({ albedo: (0.8, 0.8, 0.8), fuzz: 0.3 })
  };
  
  {
    camera,
    scene: [
      Sphere(sphere),
      Sphere(backgroundSphere),
      Sphere(rightSphere),
      Sphere(leftSphere)
    ]
  };
}

let chapter9 = ({ width, height, samples }: Camera.traceParams): t => {
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
    radius: 0.5,
    material: Lambertian({ albedo: (0.1, 0.2, 0.5) })
  };

  let backgroundSphere: Sphere.t = {
    position: (0.0, -100.5, -1.0),
    radius: 100.0,
    material: Lambertian({ albedo: (0.8, 0.8, 0.0) })
  };

  let rightSphere: Sphere.t = {
    position: (1.0, 0.0, -1.0), 
    radius: 0.5,
    material: Metal({ albedo: (0.8, 0.6, 0.2), fuzz: 1.0 })
  };

  let leftSphere: Sphere.t = {
    position: (-1.0, 0.0, -1.0), 
    radius: 0.5,
    material: Dielectric({ refractivity: 1.5 })
  };

  let leftBubbleSphere: Sphere.t = {
    position: (-1.0, 0.0, -1.0), 
    radius: -0.45,
    material: Dielectric({ refractivity: 1.5 })
  };
  
  {
    camera,
    scene: [
      Sphere(sphere),
      Sphere(backgroundSphere),
      Sphere(rightSphere),
      Sphere(leftSphere),
      Sphere(leftBubbleSphere)
    ]
  };
}
