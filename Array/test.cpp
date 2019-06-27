#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name[6];
    cout << "\nEnter your name : ";
    for(int i = 0; i < 6; i++)
    {
        getline(cin, name[i]);
    }
    for(int i = 0; i < 6; i++)
    {
        cout << "\nYou entered : " << name[i];
    }
    return 0;
}