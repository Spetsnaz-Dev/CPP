#include<iostream>
using namespace std;
typedef long long int ll;

ll t,n,q,p;
// int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 
//                         1, 2, 2, 3, 2, 3, 3, 4 }; 
/* Recursively get nibble of a given number  
and map them in the array */
// unsigned int countSetBitsRec(unsigned int num) 
// { 
//     int nibble = 0; 
//     if (0 == num) 
//         return num_to_bits[0]; 
  
//     // Find last nibble 
//     nibble = num & 0xf; 
  
//     // Use pre-stored values to find count 
//     // in last nibble plus recursively add 
//     // remaining nibbles. 
//     return num_to_bits[nibble] + countSetBitsRec(num >> 4); 
// } 
// unsigned int countSetBitsRec(unsigned int num)
// {
//     int count = 0;
//         while(num){
//             count += num & 1;
//             num >>= 1;
//         }
//     return count;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>t;
    while(t--)
    {
        // input
        cin>>n>>q;
        ll arr[n];
        register ll i = 0;
        for(i = 0; i < n; i++)
            cin>>arr[i];
        while(q--)
        {
            cin>>p;
            ll oddCount = 0, evenCount = 0;
            for(i = 0; i < n; i++){
                int x = p ^ arr[i];
                //int setBits = countSetBitsRec(x);
                int setBits = __builtin_popcount(x);
                if(setBits & 1)
                    oddCount++;
                else
                    evenCount++;
            }
            cout<<evenCount<<" "<<oddCount<<"\n";
        }
    }
    return 0;
}