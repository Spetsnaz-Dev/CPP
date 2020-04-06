#include<iostream>
#include<vector>
using namespace std;
int stockBuySell(vector<int> &price)
{
    int n = price.size();
    int i=0, buy, sell, max_profit = 0;
    while (i < n-1)
    {
        while(i<n-1 and price[i]>=price[i+1])
            i++;
        if(i >= n-1)
            break;
        buy = i++;

        while(i<=n-1 and price[i]>=price[i-1])
            i++;
        sell = i-1;
        max_profit += price[sell] - price[buy];
    }
    return max_profit;
}
int main()
 {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<stockBuySell(v)<<"\n";
    return 0;
}