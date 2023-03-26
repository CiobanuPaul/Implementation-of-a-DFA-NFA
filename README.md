# Implementation-of-a-DFA-NFA
A C++ program which receives by input a Deterministic/Nondeterministic Finite Automata and then can verify whether a word is accepted or not by the machine.
The program receives the FA through a file. On the first line it's the name of the initial state. On the second line, there are the final states, ended by a space and ';'. On the next lines there are triplets that describe the transitions(the delta function). A triplet has the form: state-letter-set_of_states. Each triplet is ended by a space and ';'. The name of the states are strings, so they can be named by preference.
To imitate the delta function, the application uses a map and the keys are tuples composed by a string and a char. This implies the use of the map, tuple, string, cstring, and even vector libraries.
The traversal of a NFA is implemented via backtracking, taking all possible routes and checking if they end on a final state.
