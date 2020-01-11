#include<iostream>
using namespace std;

void findNum(int z)
{
    //int count=0;
    int x = z-1, y= z+1;
    // int flagX = 0, flagY = 0;
    while(x>=0 && y<=21744544){
        if((x^y) == x+y){
            cout<<x<<" "<<y<<endl;
            break;
        }
        else {
            x--;y++;
        }
    }
}
int main()
{
    int z;
    cin>>z;
    findNum(z);
    
    return 0;
}