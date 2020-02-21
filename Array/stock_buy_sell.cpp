#include<iostream>
using namespace std;
void stockBuySell(int price[], int n){
    int buy, sell;

    int i = 0, flag = 0;
    while (i < n-1)
    {
        while((i < n-1) && price[i+1] <= price[i])
            i++;

        if(i >= n-1)
            break;
        buy = i++;

        while(i < n && price[i] >= price[i-1])
            i++;

        sell = i-1;
        cout<<"("<<buy<<" "<<sell<<") ";
        flag = 1;
    }
    if(flag == 0)
        cout<<"No Profit";
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
        stockBuySell(arr, n);
        cout<<"\n";
        }
	return 0;
}