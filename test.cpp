#include "bits/stdc++.h"
using namespace std;

int main(){
     int n, x;
     cin>>n;     
     priority_queue<int> pq;
     for (int i = 0; i < n; i++)
     {
         cin>>x;
         pq.push(x);
     }

     int res = 0, last = 0;
     while (!pq.empty())
     {
         int ele = pq.top();
         pq.pop();
         ele--;
         res++;
         if(last > 0){
            pq.push(last);
         }
         last = ele;
     }
     cout<<res<<"\n";
}