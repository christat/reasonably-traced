open Math;

type t = {
  camera: Camera.t,
  scene: Scene.t
};

let chapter4 = (traceParams: Camera.traceParams): t => {
  let origin = (0.0, 0.0, 0.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=90.0,
    ~focusDistance,
    ~aperture=0.0,
    ~traceParams
  );

  let sphere: Sphere.t = {
    position: (0.0, 0.0, -1.0),
    radius: 0.5,
    material: Lambertian({ albedo: (1.0, 0.0, 0.0) })
  };

  { camera, scene: [Sphere(sphere)] };
}

let chapter5 = (traceParams: Camera.traceParams): t => {
  let origin = (0.0, 0.0, 0.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=90.0,
    ~focusDistance,
    ~aperture=0.0,
    ~traceParams
  );

  let sphere: Sphere.t = {
    position: (0.0, 0.0, -1.0),
    radius: 0.5,
    material: Normal
  };

  let backgroundSphere: Sphere.t = {
    position: (0.0, -100.5, -1.0),
    radius: 100.0,
    material: Normal
  };

  { camera, scene: [Sphere(sphere), Sphere(backgroundSphere)] };
}

let chapter7 = (traceParams: Camera.traceParams): t => {
  let origin = (0.0, 0.0, 0.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=90.0,
    ~focusDistance,
    ~aperture=0.0,
    ~traceParams
  );

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

let chapter8 = (traceParams: Camera.traceParams): t => {
  let origin = (0.0, 0.0, 0.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=90.0,
    ~focusDistance,
    ~aperture=0.0,
    ~traceParams
  );

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

let chapter9 = (traceParams: Camera.traceParams): t => {
  let origin = (0.0, 0.0, 0.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=90.0,
    ~focusDistance,
    ~aperture=0.0,
    ~traceParams
  );

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

let chapter10 = (traceParams: Camera.traceParams): t => {
  let origin = (-2.0, 2.0, 1.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=20.0,
    ~focusDistance,
    ~aperture=0.0,
    ~traceParams
  );

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

let chapter11 = (traceParams: Camera.traceParams): t => {
  let origin = (3.0, 3.0, 2.0);
  let direction = (0.0, 0.0, -1.0);
  let focusDistance = Vec3f.sub(origin, direction) |> Vec3f.len;
  let camera = Camera.create(
    ~origin,
    ~direction,
    ~vFov=20.0,
    ~focusDistance,
    ~aperture=2.0,
    ~traceParams
  );

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

let chapter12 = (traceParams: Camera.traceParams): t => {
  let rec generateRandomSpheres = (~a: int=-11, ~b: int=-11, spheres: Scene.t): Scene.t => {
    let position = (float(a) +. 0.9 *. Random.float(1.0), 0.2, float(b) +. 0.9 *. Random.float(1.0));
    let updatedSpheres: Scene.t = switch (Vec3f.sub(position, (4.0, 0.2, 0.0)) |> Vec3f.len > 0.9) {
    | false => spheres
    | true => {
        let radius = 0.2;
        let sphere: Sphere.t = switch(Random.float(1.0)) {
        | r when r < 0.8 => {
            position,
            radius,
            material: Lambertian(
              {
                albedo: (
                  Random.float(1.0) ** 2.0,
                  Random.float(1.0) ** 2.0,
                  Random.float(1.0) ** 2.0
                )
              }
            )
          }
        | r when r < 0.95 => {
            position,
            radius,
            material: Metal(
              {
                albedo: (
                  0.5 *. (1.0 +. Random.float(1.0)),
                  0.5 *. (1.0 +. Random.float(1.0)),
                  0.5 *. (1.0 +. Random.float(1.0))
                ),
                fuzz: 0.5 *. Random.float(1.0)
              }
            )
          };
        | _ => { position, radius, material: Dielectric({ refractivity: 1.5 }) }
        };
        [Sphere(sphere), ...spheres];
      }
    };

    switch ((a, b + 1)) {
    | (a, _) when a >= 11 => updatedSpheres
    | (_, b) when b >= 11 => generateRandomSpheres(~a=a+1, ~b=-11, updatedSpheres)
    | (_, _) => generateRandomSpheres(~a, ~b=b+1, updatedSpheres)
    };
  };

  let background: Sphere.t = {
    position: (0.0, -1000.0, 0.0),
    radius: 1000.0,
    material: Lambertian({ albedo: (0.5, 0.5, 0.5) })
  };
  let bigDielectric: Sphere.t = {
    position: (0.0, 1.0, 0.0),
    radius: 1.0,
    material: Dielectric({ refractivity: 1.5 })
  };
  let bigLambertian: Sphere.t = {
    position: (-4.0, 1.0, 0.0),
    radius: 1.0,
    material: Lambertian({ albedo: (0.4, 0.2, 0.1) })
  };
  let bigMetal: Sphere.t = {
    position: (4.0, 1.0, 0.0),
    radius: 1.0,
    material: Metal({ albedo: (0.5, 0.5, 0.5), fuzz: 0.0 })
  };

  {
    camera: Camera.create(
      ~origin=(13.0, 2.0, 3.0),
      ~direction=(0.0, 0.0, 0.0),
      ~vFov=20.0,
      ~focusDistance=10.0,
      ~aperture=0.1,
      ~traceParams
    ),
    scene: generateRandomSpheres(
      [
        Sphere(background),
        Sphere(bigDielectric),
        Sphere(bigLambertian),
        Sphere(bigMetal)
      ]
    )
  };
}

let getExample = (~chapter: int, traceParams: Camera.traceParams): t =>
  switch chapter {
  |  4 => chapter4(traceParams)
  |  5 => chapter5(traceParams)
  |  7 => chapter7(traceParams)
  |  8 => chapter5(traceParams)
  |  9 => chapter5(traceParams)
  | 10 => chapter5(traceParams)
  | 11 => chapter5(traceParams)
  |  _ => chapter12(traceParams)
  };