# randomly generate a graph in form of adjasent matrix and store the result in file 'mygraph.txt' 
> ./<out> <graph_size> <edge_number> >mygraph.txt
example: `./out 1000 500000 >mygraph.txt`

# Run serial BFS on 'mygraph.txt'
> ./<out> <graphsize> <mygraph.txt
example: `./e1 1000  <mygraph.txt`

# Run CUDA parallel BFS on 'mygraph.txt'
> ./<out> <graphsize> <mygraph.txt
example: `./bfs 1000  <mygraph.txt`
