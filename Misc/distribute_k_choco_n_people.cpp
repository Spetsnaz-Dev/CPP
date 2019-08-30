#include<iostream>
using namespace std;
void findChoco(int n, int k)
{
    int arr[k+1] = {0};
    int i, j=0;
    int flag = 1;
    while(flag)
    {
        for(i=1;i<k+1;i++)
        {
            arr[i] += i + (j*k);
            n -= i + (j*k);
            if(n<=0){
                flag = 0;
                arr[i] = arr[i] + n;
                break;
            }
        }
        j++;
    }
    for(auto i = 1;i<k+1;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
int main() {
    int n,k;
    cin>>n>>k;
    findChoco(n, k);

    return 0;
}