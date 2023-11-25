{module, adammo}.  %% version = 0

{exports, [{test_generation,0},{module_info,0},{module_info,1}]}.

{attributes, []}.

{labels, 7}.


{function, test_generation, 0, 2}.
  {label,1}.
    {func_info,{atom,primer},{atom,test_generation},0}.
  {label,2}.
    {move,{integer,3},{x,0}}.
    {move,{x,0},{x,1}}.
    {move,{integer,4},{x,0}}.
    {move,{x,0},{x,2}}.
    {move,{integer,5},{x,0}}.
    {gc_bif,'*',{f,0},3,[{x,2}, {x,0}],{x,0}}.
    {move,{x,0},{x,2}}.
    {move,{integer,3},{x,0}}.
    {gc_bif,'*',{f,0},3,[{x,2}, {x,0}],{x,0}}.
    {gc_bif,'+',{f,0},2,[{x,0}, {x,1}],{x,0}}.
    {move,{x,0},{x,1}}.
    {move,{integer,2},{x,0}}.
    {gc_bif,'+',{f,0},2,[{x,0}, {x,1}],{x,0}}.
    return.

{function, module_info, 0, 4}.
  {label,3}.
    {line,[]}.
    {func_info,{atom,adammo},{atom,module_info},0}.
  {label,4}.
    {move,{atom,adammo},{x,0}}.
    {call_ext_only,1,{extfunc,erlang,get_module_info,1}}.


{function, module_info, 1, 6}.
  {label,5}.
    {line,[]}.
    {func_info,{atom,adammo},{atom,module_info},1}.
  {label,6}.
    {move,{x,0},{x,1}}.
    {move,{atom,adammo},{x,0}}.
    {call_ext_only,2,{extfunc,erlang,get_module_info,2}}.
