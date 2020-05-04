#include "iostream"
#include "vector"
#include "unordered_map"
#include "climits"
using namespace std;

int PerfectMatch(vector<int> arr, int n)
{
    unordered_map<int, int> mp;
    int x, r, sum, max_sum = INT_MIN, res = -1;
    for (int i = 0; i < n; i++)
    {
        x = arr[i];
        sum = 0;
        while (x)
        {
            r = x % 10 ;
            x = x / 10 ;
            sum += r;
        }
        //cout<<sum<<" ";
        if(mp[sum] != 0) {
            res = max(res, arr[i] + mp[sum]);
        }
        mp[sum] = max(mp[sum], arr[i]);
    }
    return res;
}
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout << PerfectMatch(arr,n)<<"\n";
	}
	return 0; 
}