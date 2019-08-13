#include<iostream>
#include<string>
#define MAX 101
using namespace std;
class stack
{
    private:
        string arr[MAX];
        int top;
    public:
        stack()
        { top = -1; }

        void push(string x)
        {
            if(top == MAX-1)
            {   cout<<"Error Pushing\n"; return;   }
            arr[++top] = x;
        }
        void pop()
        {
            if(top == -1)
                return;
            top--;
        }
        int size()
        {
            int temp = top;
            int c=0;
            while(temp != -1)
                {c++; temp--;}
            
            return c;
        }
        void clear()
        {
            top = -1;
        }
        bool isEmpty()
        {   
            if(top == -1)
                return 1;
            else
                return 0;
        }
};
int findJumps(string str)
{
    stack s;
    int c = 0; //counter
    int l = sizeof(str)/sizeof(str[0]);
    for(int i=0;i<l;i++)
    {
        if(str[i]== 'x' && str[i+1]== '/')
        {   //Comment represents solution only using array
            s.push("x/");
            //c += 1;
            i++;
        }
        else if(str[i]== '.' && str[i+1]== '.')
        {
            // s.push("..");
            // i++;
            // c = 0;
            s.clear();
        }
    }
    return s.size();
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        cout<<findJumps(s)<<"\n";
    }
    return 0;
}