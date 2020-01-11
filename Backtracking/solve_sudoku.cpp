#include<iostream>
#define INIT 0
using namespace std;
void displaySudoku(int arr[][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        //cout<<"\n";
    }
}
bool isSafeRow(int arr[][9], int row, int col, int num)
{
    //check that row
    for(int col=0;col<9;col++)
        if(arr[row][col] == num)
            return true;
    return false;
}
bool isSafeCol(int arr[][9], int row, int col, int num)
{
    //check that col
    for(int row=0;row<9;row++)
        if(arr[row][col] == num)
            return true;
    return false;
}
bool isSafeBox(int arr[][9], int box_row_start, int box_col_start, int num)
{
    //check that 3x3 box
    for(int row=0;row<3;row++)
        for(int col=0;col<3;col++)
            if(arr[row+box_row_start]
                  [col+box_col_start] == num)
                  return true;
    return false;
}
bool isSafe(int arr[][9], int row, int col, int num)
{
    return !isSafeRow(arr, row, col, num) &&
            !isSafeCol(arr, row, col, num) &&
            !isSafeBox(arr, row-row%3, col-col%3, num) &&
            arr[row][col] == INIT;
}
bool haveUnassignedLocation(int arr[][9], int &row, int &col)
{
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
            if(arr[row][col] == INIT)
                return true;
    return false;
}
bool solveSudoku(int arr[][9])
{
    int row, col;
    
    if(!haveUnassignedLocation(arr, row, col))
        return true;
        
    for(int num=1;num<=9;num++)
    {
        if(isSafe(arr, row, col, num))
        {
            arr[row][col] = num;
            if(solveSudoku(arr))
                return true;
            
            arr[row][col] = INIT;   //backtrack
        }
    }
    return false;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int arr[9][9];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>arr[i][j];
                
        solveSudoku(arr);
        displaySudoku(arr);
        cout<<"\n";
    }
	return 0;
}