#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& arr,vector<int>& rot,int r,int c,int layers)
{
	int sub=0;
	//cout<<"Layers are: "<<layers<<"\n";
	for(int l=0;l<layers;++l)
	{
		int size = 2*(r-sub)+2*(c-2-sub);
		rot[l] %=size;

		if(l%2==1)
			rot[l] = size-rot[l];
		
		vector<int> vec(size);
		//Store value in rotated form in 1D array (Vec)
		//TOP-DOWN
		int temp = rot[l];
		for(int i=l;i<r-l;++i)
		{
			vec[temp] = arr[i][l];
			temp+=1;
			temp%=size;
		}
	
		//LEFT-RIGHT (Last row)
		for(int j=l+1;j<c-l-1;++j)
		{
			vec[temp] = arr[r-l-1][j];
			temp+=1;
			temp%=size;
		}
		
		//DOWN-TOP (Last Col)
		for(int i=r-l-1;i>=l;--i)
		{
			vec[temp] = arr[i][c-l-1];
			temp+=1;
			temp%=size;
		}
		
		//RIGHT-LEFT(1st row)
		for(int j=c-l-2;j>l;j--)
		{
			vec[temp] = arr[l][j];
			temp+=1;
			temp%=size;
		}
		sub+=2;

		//Update new ring
		temp = 0;
		for(int i=l;i<r-l;++i)
		{
			arr[i][l] = vec[temp];
			temp+=1;
		}
		for(int j=l+1;j<c-l-1;++j)
		{
			arr[r-l-1][j] = vec[temp];
			temp+=1;
		}
		for(int i=r-l-1;i>=l;--i)
		{
			arr[i][c-l-1] = vec[temp];
			temp+=1;
		}
		for(int j=c-l-2;j>l;j--)
		{
			arr[l][j] = vec[temp];
			temp+=1;
		}
	}
}

void printMatrix(vector<vector<int>>& arr,int n,int m)
{
	//cout<<"MATRIX:\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> arr(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;++j)
			cin>>arr[i][j];

	int layers = min(m,n)/2;
	vector<int> rot(layers);
	for(int i=0;i<layers;++i)
		cin>>rot[i];

	solve(arr,rot,n,m,layers);
	printMatrix(arr,n,m);
	return 0;
}