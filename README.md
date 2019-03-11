# Reasonably traced
Peter Shirley's [Ray Tracing in One Weekend](http://in1weekend.blogspot.com/2016/01/ray-tracing-in-one-weekend.html) written in ReasonML.

## FAQ

**Q:** Why did you decide to do this?

> **A:** Because Reasonml/Ocaml are super cool!

**Q:** No, but... why?

> **A:** I know, writing a Whitted ray tracer in a functional, garbage-collected language doesn't sound very reasonable (pun not intended).
However, I believe this is a great project to get acquainted with a new language, which is exactly what this is about :)

**Q:** How can I play around with this?

> **A:** You can select a scene from `Examples.re` and replace the invocation in `Main.re`, or use the CLI parameters as seen in `Main.re`. To build/run, execute `make build` and then run the executable `reasonably-traced` under `_build/install/default/bin`. The output goes by default to a file called `reasonably_traced.ppm`.

![Final chapter render](https://github.com/christat/reasonably-traced/blob/master/img/reasonably_traced.jpg)
