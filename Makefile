all: p1 p2 p3

p1: graph_gen.cpp
	g++ graph_gen.cpp -o out

p2: s_bfs.cpp
	g++ s_bfs.cpp -o e1

p3: bfs.cu
	nvcc bfs.cu -o bfs


