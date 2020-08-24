all:
	g++ -Wall -pedantic Graph.cpp Solution.cpp Main.cpp -o solution_exe

clean:
	rm -f solution_exe