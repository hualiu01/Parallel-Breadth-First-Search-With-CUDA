// This is a serial Breath First Search (BFS) Implementation
// Input: randomly generated graph in form of adjacent matrix stored in 'mygraph.txt'
// BFS starts from node 0 and stops when the logical BFS tree is formed
// usage: ./<out> <graph_size> <mygraph.txt

#include <cstdlib>
#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

void bfs(int** adj_mat, const int N){ 
	queue<int> q;
	q.push(0);
	bool* visited = (bool*)malloc(N*sizeof(bool));
	for(int i=0;i<N;i++)
		visited[i] = false;

	// dequeue all
	int cn = 0; 
	while(!q.empty()){
		int idx = q.front();
		cn++;
		q.pop();

		//for each adj_mat[idx] row equeue unvisited
		for(int j=0;j<N;j++){
			if(adj_mat[idx][j] && !visited[j]){
				visited[j] = true;
				q.push(j);
			}
		}
	}
	
	cout<<"queue through put: "<< cn<<endl;
}

void recur_kernel(int** adj_mat, const int N, queue<int>* q, bool* visited){
	int cn =0;
	while(!q->empty()){
		int idx = q->front();
		cn++;
		q->pop();
		for(int j=0; j<N; j++){	
			if(adj_mat[idx][j] && !visited[j]){
				q->push(j);
				visited[j] = true;
			}
		}
	}
	recur_kernel(adj_mat, N, q, visited);
}
void bfs_recur(int** adj_mat, const int N){	
	queue<int> q;
	q.push(0);
	bool* visited = (bool*)malloc(N*sizeof(bool));
	for(int i=0;i<N;i++)
		visited[i] = false;
	
	recur_kernel(adj_mat, N, &q, visited);
	
}

int main(int arg, char** argv){
	if(arg!=2){
		cout<<"usage: ./<out> <graph_size> >mygraph.txt"<<endl;
		return -1;
	}
	const int N = atoi(argv[1]);
	//read graph from mygraph.txt
	int** adj_mat = (int**)malloc(N*sizeof(int*));
	for(int row=0; row<N; row++)
		adj_mat[row] = (int*)malloc(N*sizeof(int));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			string a;
			cin>>a;
			if(a=="1") adj_mat[i][j] = 1;
			else adj_mat[i][j] = 0;
		}			
	}
	
	clock_t start,end;
	start = clock();
	bfs(adj_mat,N);
	end = clock();
	cout << "sequntial (loop) BFS uses " << double(end - start) << " us"<< endl;

	// start = clock();
	// bfs_recur(adj_mat,N);
	// end = clock();
	// cout << "sequntial (recursive) BFS uses " << double(end - start) << " us"<< endl;

	return 0;
}
