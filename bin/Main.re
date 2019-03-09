let () = {
  let traceParams: Camera.traceParams = 
    switch (Sys.argv) {
    | [| _, "--width", w, "--height", h, "--samples", s |] =>
      {
        width: int_of_string(w),
        height: int_of_string(h),
        samples: int_of_string(s)
      }
    | _ => Camera.defaultParams
    };
 
  let { camera, scene }: Examples.t = Examples.chapter10(traceParams);

  Tracer.trace(~x=0, ~y=traceParams.height-1, ~camera, ~scene, []) |> ignore;
};
