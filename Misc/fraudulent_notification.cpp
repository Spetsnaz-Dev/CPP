// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <map>
// #include <set>
// #include <string>

// using namespace std;
// typedef long long ll;
// const int MAXN = 200100;
// const int MAXD = 210;

// int N, D;
// int arr[MAXN];

// int nval[MAXD] = {0};

// int fval (int x)
// {
//     for (int i = 0; i < MAXD; i++)
//     {
//         if (nval[i] >= x)
//             return i;
//         x -= nval[i];
//     }
//     return 0;
// }

// int main()
// {
//     cin >> N >> D;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> arr[i];
//     }

//     // for (int i = 0; i < MAXD; i++)
//     //     nval[i] = 0;

//     int ans = 0;
//     for (int i = 0; i < N; i++)
//     {
//         if (i >= D)
//         {
//             int mval = fval (D / 2 + 1) + fval ((D + 1) / 2);
//             //cout << mval << " " << arr[i] << "\n";
//             if (arr[i] >= mval)
//                 ans++;
//         }

//         nval[arr[i]]++;
//         if (i >= D)
//         {
//             nval[arr[i-D]]--;
//         }
//     }

//     cout << ans << "\n";
//     return 0;
// }
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int val(vector<int> vec)
{
    int sum=0;
    for(int i=0;i<vec.size();i++)
        sum+=vec[i];
    if(sum%2==1)
    {
        sum=(sum/2)+1;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>=sum)
                return i*2;
            sum-=vec[i];
        }
    }
    int val1=-1,val2=-1;
    sum=sum/2;
    int sum2=sum+1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]>=sum)
        {
            val1=i;
            break; 
        }
        sum-=vec[i];
    }
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]>=sum2)
        {
            val2=i;
            break; 
        }
        sum2-=vec[i];
    }
    return val1+val2;
}
int main() {
    int n,d;
    cin >> n >> d;
    vector<int> vec(n);
    vector<int> count(201);
    for(int i=0;i<n;i++)
        cin >> vec[i];
    for(int i=0;i<d;i++)
        count[vec[i]]++;    
    int res=0;
    for(int i=d;i<n;i++)
    {
        if(val(count)<=vec[i])
            res++;
        count[vec[i]]++;
        count[vec[i-d]]--;
    }
    cout << res << endl;
    return 0;
}
