#include "bits/stdc++.h"
using namespace std;

int findMax(vector<int>& v1){
        int val1;
        for(auto i=0; i < v1.size(); i++){
            if(v1[i] != 9){
                val1 = v1[i];
                i=0;
                while(i < v1.size()){
                    if(v1[i] == val1)
                        v1[i] = 9;
                    i++;
                }
                break;
            }
        }
        int a = 0;
        for(auto i : v1)
            a = a * 10 + i;
        return a;
    }
    int findMin(vector<int>& v){
        int first = v[0], val;
        for(int i=0; i < v.size(); i++){
            if(v[0] != 1){
                val = v[0];
                while(i < v.size()){
                    if(v[i] == val)
                        v[i] = 1;
                    i++;
                }
                break;
            }
            else if(i > 0 and v[i] != first and v[i] > 0){
                val = v[i];
                // int curr = 0;
                while(i < v.size()){
                    if(v[i] == val)
                        v[i] = 0;
                    i++;
                }
                break;
            }
        }
        int b = 0;
        for(auto i : v)
            b = b * 10 + i;
        return b;
    }
    int maxDiff(int num) {
        int x, y, a = 0, b = 0, r;
        vector<int> v1, v2;
        
//         1st step
        int temp = num;
        while(temp){
            r = temp % 10;
            v1.push_back(r);
            v2.push_back(r);
            temp = temp / 10;
        }
        
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        
        //         step 2
        x = findMax(v1);
        cout<<"x is - "<<x<<endl;
        y = findMin(v2);
        cout<<"y is - "<<y<<endl;
        
        return x - y;
    }
int main()
{
    // Input
    int num;
    cin>>num;

    cout<<maxDiff(num)<<"\n";

    return 0;
}
