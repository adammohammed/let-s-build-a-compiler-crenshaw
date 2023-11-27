# Bad code here

This is me attempting to port the Turbo Pascal implementation to C.

You can build it by being in this directory and then running:

```
gcc main.c -o my_compiler
```

After that, you can start the compiler:

```
./my_compiler
```

Then, enter your math expression, and the compiler will output BEAM instructions.

```
$ ./my_compiler
3+4*5-2
    {move,{integer,3},{x,0}}.
    {move,{x,0},{x,1}}.
    {move,{integer,4},{x,0}}.
    {move,{x,0},{x,2}}.
    {move,{integer,5},{x,0}}.
    {gc_bif,'*',{f,0},3,[{x,2}, {x,0}],{x,0}}.
    {gc_bif,'+',{f,0},2,[{x,0}, {x,1}],{x,0}}.
    {move,{x,0},{x,1}}.
    {move,{integer,2},{x,0}}.
    {gc_bif,'-',{f,0},2,[{x,0}, {x,1}],{x,0}}.
```


Testing the output is done by replacing `##INSTRUCTIONSHERE##` in
`adammo.S` with the output of the compiler.

```
{function, test_generation, 0, 2}.
  {label,1}.
    {func_info,{atom,primer},{atom,test_generation},0}.
  {label,2}.
    ##INSTRUCTIONSHERE##
    return.
```


You can then load into an erlang repl by doing:

```bash
$ erl -mode interactive
Eshell V13.2.2.4  (abort with ^G)
1> c(adammo).
Recompiling /path/to/build-a-compiler/src/adammo.S
{ok,adammo}
2> adammo:test_generation().
