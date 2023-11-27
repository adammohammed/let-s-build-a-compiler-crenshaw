# Let's Build a Compiler

This is a series from Jack Crenshaw about builidng a basic [compiler].

His implementation is in Turbo Pascal, and this is a barely functional
C version. Though it's good enough to figure out the concepts.

In Crenshaw's version, he's compiling for the 68000 series CPUs, I've
changed this to produce instructions for the BEAM virtual machine that
powers Erlang and Elixir.

Check out the [src/README.md](./src/README.md) for more info.


[compiler]: https://compilers.iecc.com/crenshaw/
