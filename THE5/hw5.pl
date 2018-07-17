:- module(hw5, [configuration/3]).
:- [hardware].

in(X) :- sections(L),member(X,L),findall(Y,(adjacent(X,Y);adjacent(Y,X)),Lis), length(Lis,4).

configure([],_,[]).
configure([X|Rest],L,Result) :- member(A,L), delete(L,A,L1), configure(Rest,L1,Result1), Result = [put(X,A) | Result1].

configuration([],_,[]) :- !.
configuration(X,[],Z) :- !,sections(L), configure(X,L,Z).
configuration(X,[outer_edge(A)|Rest],Z) :- !,configuration(X,Rest,Z), member(put(A,I),Z), not(in(I)).
configuration(X,[close_to(A,B)|Rest],Z) :- !,configuration(X,Rest,Z), member(put(A,K),Z),member(put(B,L),Z), (adjacent(K,L);adjacent(L,K)).
