#include<bits/stdc++.h>
using namespace std;
int n=0;
vector<vector<int> > sol( n , vector<int> (n, 0));  
void display(vector<int> v) 
{ 
    cout<<'[';
    for (int i = 0; i < v.size(); i++) { 
        cout << v[i] << " "; 
    } 
    cout <<']'<<"\n"; 
} 
void permutePrintArray(vector<int> v)
{
    sort(v.begin(), v.end());
    while(next_permutation(v.begin(), v.end()))
        display(v);
}
void printSolution(vector<vector<int>> sol)
{
    vector<int> v;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(sol[i][j]>0)
                v.push_back(sol[i][j]);
    permutePrintArray(v);
}
bool isSafe(vector<vector<int>> sol, int row, int col, int n)
{
    //int n= sol[0].length();
    //check from curret to left-most of the board
    for(int i=0;i<col;i++)
        if(sol[row][i]>0)
            return false;
    //check for upper-left diagonal elements
    for(int i=row, j=col;i>=0 && j>=0;i--,j--)
        if(sol[i][j]>0)
            return false;
    //check for lower-left diagonal element
    for(int i=row, j=col;i<n && j>=0;i++,j--)
        if(sol[i][j]>0)
            return false;
            
    return true;
}
bool placeQueens(vector<vector<int>> sol, int col, int n)
{
    //int n= sol[0].length();
    
    if(col>=n)
        return true;
        
    for(int i=0;i<col;i++){
        if(isSafe(sol, i, col, n)){
            sol[i][col] = i;
        
        if(placeQueens(sol, col+1, n))
            return true;
        
        sol[i][col] = 0;    //backtrack
        }
    }
    return false;
}
void nQueens(int n)
{
    // int sol[n][n];  //assign 0 to each element
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sol[i][j] = 0;
    
    if(placeQueens(sol, 0, n) == false)
        cout<<"-1\n";
    else
        printSolution(sol);
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        cin>>n;
        //sol.assign(sol.begin(), sol.end(), 0);
        
        nQueens(n);
        }
	return 0;
}