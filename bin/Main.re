let () = {
  let { camera, scene }: Examples.t = switch (Sys.argv) {
  | [| _, "--width", w, "--height", h, "--samples", s, "--chapter", c |] =>
      Examples.getExample(
        ~chapter=int_of_string(c),
        { width: int_of_string(w), height: int_of_string(h), samples: int_of_string(s) }
      )
  | _ => Examples.chapter12(Camera.defaultParams)
  };

  Tracer.trace(~x=0, ~y=camera.traceParams.height-1, ~camera, ~scene, []) |> ignore;
};
