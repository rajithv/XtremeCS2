#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

ifstream fin("bfs.in");

int main(){
	
	int n; // no of nodes
	int m; // no of paths
	int s; // start node
	
	queue <int> front; // discovered node list
	
	int t1, t2; // temp to store paths
	
	fin >> n >> m >> s;
	
	bool graph[n][n]; // graph as an adjacency matrix
	bool grey[n]; // grey list
	
	// initialize the local graphs to 0 (all false)
	memset (graph, 0, sizeof(bool) * n * n);
	memset (grey, 0, sizeof(bool) * n);
	
	
	// get the input and save it as a adjacency matrix
	for(int i=0; i<m; ++i){
		fin >> t1 >> t2;
		
		graph[t1][t2] = true;
		graph[t2][t1] = true;
		
	}
	
	// start traversing from the start node
	front.push(s);
	grey[s] = true;
	
	int current; // current node
	
	// run the BFS until there are no more unexplored, discovered nodes
	while(!front.empty()){
		
		// explore the node at the top of the discovered list
		current = front.front();
		cout << current << " ";
		
		for(int i=0; i<n; i++){
			
			// if connected, add the node to the frontier
			if(graph[current][i] && !grey[i]){
				grey[i] = true;
				front.push(i);
			}
		}
		
		// after exploring, remove the node
		front.pop();
	}
	
	cout << endl; // optional to flush the output 
}