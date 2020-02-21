// C++ code to find out minimum cost 
// path to connect all the cities 
#include <iostream> 
#include <limits> 
#include <vector> 

using namespace std; 

// Function to find out minimum valued node 
// among the nodes which are not yet included in MST 
int minnode(int n, int keyval[], bool mstset[]) { 
int mini = numeric_limits<int>::max(); 
int mini_index; 

// Loop through all the values of the nodes 
// which are not yet included in MST and find 
// the minimum valued one. 
for (int i = 0; i < n; i++) { 
	if (mstset[i] == false && keyval[i] < mini) { 
	mini = keyval[i], mini_index = i; 
	} 
} 
return mini_index; 
} 

// Function to find out the MST and 
// the cost of the MST. 
void findcost(int n, vector<vector<int>> city) { 

// Array to store the parent node of a 
// particular node. 
int parent[n]; 

// Array to store key value of each node. 
int keyval[n]; 

// Boolean Array to hold bool values whether 
// a node is included in MST or not. 
bool mstset[n]; 

// Set all the key values to infinite and 
// none of the nodes is included in MST. 
for (int i = 0; i < n; i++) { 
	keyval[i] = numeric_limits<int>::max(); 
	mstset[i] = false; 
} 

// Start to find the MST from node 0. 
// Parent of node 0 is none so set -1. 
// key value or minimum cost to reach 
// 0th node from 0th node is 0. 
parent[0] = -1; 
keyval[0] = 0; 

// Find the rest n-1 nodes of MST. 
for (int i = 0; i < n - 1; i++) { 

	// First find out the minimum node 
	// among the nodes which are not yet 
	// included in MST. 
	int u = minnode(n, keyval, mstset); 

	// Now the uth node is included in MST. 
	mstset[u] = true; 

	// Update the values of neighbor 
	// nodes of u which are not yet 
	// included in MST. 
	for (int v = 0; v < n; v++) { 

	if (city[u][v] && mstset[v] == false && 
		city[u][v] < keyval[v]) { 
		keyval[v] = city[u][v]; 
		parent[v] = u; 
	} 
	} 
} 
// Find out the cost by adding 
// the edge values of MST. 
int cost = 0; 
for (int i = 1; i < n; i++) 
	cost += city[parent[i]][i]; 
cout << cost << endl; 
} 
int main() { 
// Input 1 
int n1 = 5; 
vector<vector<int>> city1 = {{0, 1, 2, 3, 4}, 
							{1, 0, 5, 0, 7}, 
							{2, 5, 0, 6, 0}, 
							{3, 0, 6, 0, 0}, 
							{4, 7, 0, 0, 0}}; 
findcost(n1, city1); 

return 0; 
} 
