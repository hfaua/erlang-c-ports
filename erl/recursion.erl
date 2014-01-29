-module(recursion).
-export([solve/2]).

solve(L, N) -> solve(L, N, 0).

solve(_, N, N) -> true;
solve([], _, _) -> false;
solve([H | T], N, A) ->
	solve(T, N, A + H) orelse solve(T, N, A).
