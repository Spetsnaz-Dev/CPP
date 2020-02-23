// C++ program to sort elements by frequency using 
#include <bits/stdc++.h> 
using namespace std; 

// function to compare two pairs for inbuilt sort 
bool compare(pair<int,int> &p1, 
			pair<int, int> &p2) 
{ 
	// If frequencies are same, compare 
	// values 
	if (p1.second == p2.second) 
		return p1.first < p2.first; 
	return p1.second > p2.second; 
} 

// function to print elements sorted by freq 
void printSorted(int arr[], int n) 
{ 
	// Store items and their frequencies 
	map<int, int> m; 
	for (int i = 0; i < n; i++) 
		m[arr[i]]++; 

	// no of distinct values in the array 
	// is equal to size of map. 
	int s = m.size(); 

	// an array of pairs 
	pair<int, int> p[s]; 

	// Fill (val, freq) pairs in an array 
	// of pairs. 
	int i = 0; 
	for (auto it = m.begin(); it != m.end(); ++it) 
		p[i++] = make_pair(it->first, it->second); 

	// sort the array of pairs using above 
	// compare function. 
	sort(p, p + s, compare); 

	cout << "Elements sorted by frequency are: "; 
	for (int i = 0; i < s; i++) 
	{ 
		int freq = p[i].second; 
		while (freq--) 
			cout << p[i].first << " "; 
	} 
} 

// driver program 
int main() 
{ 
	int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 
				3, 3, 12}; 
	int n = sizeof(arr)/ sizeof(arr[0]); 
	printSorted(arr, n); 
	return 0; 
} 
