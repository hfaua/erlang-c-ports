-module(test).
-export([start/1, stop/0, init/1, compute/1]).

start(Program) ->
    spawn(?MODULE, init, [Program]).

stop() ->
    process ! stop.

compute(Message) ->
    process ! {call, self(), Message},
    receive
	{response, Result} ->
	    Result
    end.

init(Program) ->
    register(process, self()),
    process_flag(trap_exit, true),
    Port = open_port({spawn, Program}, [{packet, 1}]),
    loop(Port).

loop(Port) ->
    receive
	{call, Caller, Message} ->
	    Port ! {self(), {command, Message}},
	    receive
		{Port, {data, Data}} ->
		    Caller ! {response, Data}
	    end,
	    loop(Port);
	stop ->
	    Port ! {self(), close},
	    receive
		{Port, closed} ->
		    exit(normal)
	    end;
	{'EXIT', Port, _} ->
	    exit(port_terminated)
    end.
