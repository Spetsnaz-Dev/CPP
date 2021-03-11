#include<bits/stdc++.h>
using namespace std;

bool StraightFlush(vector<int> hand[])
{
    for(int i=0;i<4;i++)
    {
        int count=0;
        for(int j=0;j<13;j++)
        {
            if(hand[i][j]==1)
            count++;
            else 
            count=0;

            if(count==5)
            return true;
        }
    }
    return false;
}
bool FourOfAKind(vector<int> hand[])
{
    for(int j=0;j<13;j++)
    {
        int count=0;
        for(int i=0;i<4;i++)
        {
            if (hand[i][j]==1)
            count++;
        }
        if(count==4)
        return true;
    }
    return false;    
}
bool FullHouse(vector<int> hand[])
{
    bool CardGroup3=false,CardGroup2=false;
    for(int j=0;j<13;j++)
    {
        int count=0;
        for(int i=0;i<4;i++)
        {
            if (hand[i][j]==1)
            count++;
        }
        if(count==3)
        CardGroup3=true;
        else if(count==2)
        CardGroup2=true;

    }
    if(CardGroup3 && CardGroup2)
    return true;
    else
    return false;    
}
bool Flush(vector<int> hand[])
{
    for(int i=0;i<4;i++)
    {
        int count=0;
        for(int j=0;j<13;j++)
        {
            if(hand[i][j]==1)
            count++;    
        }
        if(count==5)
        return true;
    }
    return false;
}
bool Straight(vector<int> hand[])
{
    
    int count=0;
    for(int j=0;j<13;j++)
    {
        bool flag=false;
        for(int i=0;i<4;i++)
        {
            if(hand[i][j]==1)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        count++;
        else
        count=0;

        if(count==5)
        return true;
    }
    
    return false;
}
bool ThreeOfAKind(vector<int> hand[])
{
    for(int j=0;j<13;j++)
    {
        int count=0;
        for(int i=0;i<4;i++)
        {
            if (hand[i][j]==1)
            count++;
        }
        if(count==3)
        return true;
    }
    
    return false;
}
bool TwoPairs(vector<int> hand[])
{
    bool pair1=false,pair2=false;
    for(int j=0;j<13;j++)
    {
        int count=0;
        for(int i=0;i<4;i++)
        {
            if (hand[i][j]==1)
            count++;
        }
        if(count==2 && pair1==false)
        pair1=true;
        else if(count==2 && pair1)
        return true;

    }
    
    return false;
}
bool Pair(vector<int> hand[])
{
    for(int j=0;j<13;j++)
    {
        int count=0;
        for(int i=0;i<4;i++)
        {
            if (hand[i][j]==1)
            count++;
        }
        if(count==2)
        return true;
    }
    
    return false;
}


int compute_rank(vector<int> hand[])
{
    if(StraightFlush(hand))
    {
        return 1;
    }
    else if(FourOfAKind(hand))
    {
        return 2;
    }
    else if(FullHouse(hand))
    {
        return 3;
    }
    else if(Flush(hand))
    {
        return 4;
    }
    else if(Straight(hand))
    {
        return 5;
    }
    else if(ThreeOfAKind(hand))
    {
        return 6;
    }
    else if(TwoPairs(hand))
    {
        return 7;
    }
    else if(Pair(hand))
    {
        return 8;
    }
    else
    {
        return 9;
    }
}

void store(vector<int> arr[],string str)
{
    for(int i=0;i<str.length();i=i+3)
    {
        int x,y;
        // locating row
        if(str[i]=='S')
        {
            x=0;
        }
        else if(str[i]=='H')
        {
            x=1;
        }
        else if(str[i]=='D')
        {
            x=2;
        }
        else if(str[i]=='C')
        {
            x=3;
        }

        // locating column
        if(str[i+1]=='A')
        {
            y=12;
        }
        else if(str[i+1]=='K')
        {
            y=11;
        }
        else if(str[i+1]=='Q')
        {
            y=10;
        }
        else if(str[i+1]=='J')
        {
            y=9;
        }
        else if (str[i+1]=='T')
        {
            y=8;
        }
        else if(str[i+1]>='2' && str[i+1]<='9')
        {
            y=str[i+1]-'0'-2;
        }

        arr[x][y]=1;
    }
}

void DrawCheck_1(vector<int> hand1[],vector<int> hand2[],bool &win1,bool &win2)
{
    for(int j=12;j>=0;j--)
    {
        int count1=0,count2=0;
        for(int i=0;i<4;i++)
        {
            if(hand1[i][j]==1)
            count1++;

            if(hand2[i][j]==1)
            count2++;
        }
        if(count1>count2)
        {
            win1=true;
            return;
        }
        else if(count2>count1)
        {
            win2=true;
            return;
        }
    }
}

vector<int> LocationFinder(vector<int> hand[],int c)
{
    vector<int> res;
    for(int j=12;j>=0;j--)
    {
        int count=0;
        for(int i=0;i<4;i++)
        {
            if (hand[i][j]==1)
            count++;
        }
        if(count==c)
        res.push_back(j);
    }
    return res;
}

void DrawCheck_2(vector<int> hand1[],vector<int> hand2[],bool &win1,bool &win2)
{
    vector<int> loc1=LocationFinder(hand1,4);
    vector<int> temp=LocationFinder(hand1,1);
    loc1.insert(loc1.end(),temp.begin(),temp.end());

    vector<int> loc2=LocationFinder(hand2,4);
    temp=LocationFinder(hand2,1);
    loc2.insert(loc2.end(),temp.begin(),temp.end());

    for(int i=0;i<loc1.size();i++)
    {
        if(loc1[i]>loc2[i])
        {
            win1=true;
            return;
        }
        else if(loc2[i]>loc1[i])
        {
            win2=true;
            return;
        }
    }  
}
void DrawCheck_3(vector<int> hand1[],vector<int> hand2[],bool &win1,bool &win2)
{
    vector<int> loc1=LocationFinder(hand1,3);
    vector<int> temp=LocationFinder(hand1,2);
    loc1.insert(loc1.end(),temp.begin(),temp.end());

    vector<int> loc2=LocationFinder(hand2,3);
    temp=LocationFinder(hand2,2);
    loc2.insert(loc2.end(),temp.begin(),temp.end());

    for(int i=0;i<loc1.size();i++)
    {
        if(loc1[i]>loc2[i])
        {
            win1=true;
            return;
        }
        else if(loc2[i]>loc1[i])
        {
            win2=true;
            return;
        }
    } 
}
void DrawCheck_4(vector<int> hand1[],vector<int> hand2[],bool &win1,bool &win2)
{
    vector<int> loc1=LocationFinder(hand1,3);
    vector<int> temp=LocationFinder(hand1,1);
    loc1.insert(loc1.end(),temp.begin(),temp.end());

    vector<int> loc2=LocationFinder(hand2,3);
    temp=LocationFinder(hand2,1);
    loc2.insert(loc2.end(),temp.begin(),temp.end());

    for(int i=0;i<loc1.size();i++)
    {
        if(loc1[i]>loc2[i])
        {
            win1=true;
            return;
        }
        else if(loc2[i]>loc1[i])
        {
            win2=true;
            return;
        }
    }
}
void DrawCheck_5(vector<int> hand1[],vector<int> hand2[],bool &win1,bool &win2)
{
    vector<int> loc1=LocationFinder(hand1,2);
    vector<int> temp=LocationFinder(hand1,1);
    loc1.insert(loc1.end(),temp.begin(),temp.end());

    vector<int> loc2=LocationFinder(hand2,2);
    temp=LocationFinder(hand2,1);
    loc2.insert(loc2.end(),temp.begin(),temp.end());

    for(int i=0;i<loc1.size();i++)
    {
        if(loc1[i]>loc2[i])
        {
            win1=true;
            return;
        }
        else if(loc2[i]>loc1[i])
        {
            win2=true;
            return;
        }
    }
}



int main()
{
    //input
    string s;
    while (cin>>s)
    {
        string str1,str2;
        cin>>str1>>str2;

        //initializing 2-D array to store each hand at a time and compute
        vector<int> hand1[4];
        vector<int> hand2[4];
        for(int i=0;i<4;i++)
        {
            vector<int> temp;
            for(int j=0;j<13;j++)
            {
                temp.push_back(0);
            }
            hand1[i]=temp;
            hand2[i]=temp;
        }


        //storing values in 2-D arrays respectively
        store(hand1,str1);
        store(hand2,str2);

        //getting rank of both hands
        int rank1=compute_rank(hand1);
        int rank2=compute_rank(hand2);
        // cout<<rank1<<" "<<rank2<<" ";

        //printing results
        if(rank1<rank2)
        cout<<"Hand 1 wins"<<endl;
        else if(rank2<rank1)
        cout<<"Hand 2 wins"<<endl;
        else if(rank1==rank2)
        {
            bool win1=false,win2=false;
            if(rank1==1 || rank1==4 || rank1==5 || rank1==9)
            {
                DrawCheck_1(hand1,hand2,win1,win2);
            }
            else if (rank1==2) //four of a kind
            {
                DrawCheck_2(hand1,hand2,win1,win2);
            }
            else if(rank1==3)
            {
                DrawCheck_3(hand1,hand2,win1,win2);
            }
            else if(rank1==6)
            {
                DrawCheck_4(hand1,hand2,win1,win2);
            }
            else if(rank1==7 || rank1==8)
            {
                DrawCheck_5(hand1,hand2,win1,win2);
            }


            if(win1)
            cout<<"Hand 1 wins"<<endl;
            else if(win2)
            cout<<"Hand 2 wins"<<endl;
            else
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}