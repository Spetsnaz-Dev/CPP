//Find no of students who will not be able to eat lunch
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Input
    int n;
    cin>>n;
    stack<int> s;
    queue<int> q;
    int box[n], students[n];
    int count1 =0, count0 = 0;
    for(int i=0;i<n;i++)
    {
        cin>>box[i];
        if(box[i] == 1)
            count1++;
        s.push(box[i]);
    }
    for(int i=0;i<n;i++)
    {
        cin>>students[i];
        if(students[i]==1)
            count0++;
        q.push(students[i]);
    }
    //Main Program
    cout<<abs(count1-count0)<<"\n";
    // while(!q.empty() || s.empty())
    // {
    //     int student= q.front();
    //     int box = s.top();
    //     if(student == box)
    //     {
    //         q.pop();
    //         s.pop();
    //     }
    //     else
    //     {
    //         q.pop();
    //         q.push(student);
    //     }
    // }
    // cout<<q.size()<<"\n";
}