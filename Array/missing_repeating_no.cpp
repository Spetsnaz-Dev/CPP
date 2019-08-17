#include<iostream>
using namespace std;
void find_Repeat_Missing(int arr[], int n)
{
    int v[2];
    int i;
    bool check[n+1] = {0};
    //memset(check, 0, n);
    for(i=0;i<n;i++)
    {
        if(check[arr[i]] == 1)
        {
            v[0] = arr[i];
        }
        else
        {
            check[arr[i]] = 1;
        }
    }
    i=1;
    while(check[i] == 1)
        i++;
    v[1] = i;
    
    cout<<v[0]<<" "<<v[1]<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        find_Repeat_Missing(arr, n);
    }
	return 0;
}