# ReasonablyTraced
Another go at [Ray Tracing in One Weekend](), this time using Reasonml.

## FAQ

**Q:** Why did you decide to do this?

> **A:** Because Reasonml/Ocaml are super cool!

**Q:** No, but... why?

> **A:** I know, writing a Whitted ray tracer in a functional, garbage-collected language doesn't sound very reasonable (pun not intended).
However, I believe this is a great project to get acquainted with a new language, which is exactly what this is about :)

**Q:** How can I play around with this?

> **A:** You can select a scene from `Examples.re` and replace the invocation in `Main.re`, or use the CLI parameters as seen in `Main.re`. To build/run, execute `make build` and then run the executable `reasonably-traced` under `_build/install/default/bin`. The output goes to STDOUT, you can redirect it to a `.ppm` file to visualize.
