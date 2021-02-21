#include "bits/stdc++.h"
using namespace std;

// storing ranks
map<string, int> mp;
/**
 *  5*14 grid to mark card number with corresponding card
 * row -> group of card (1-S, 2-C, 3-H, 4-D)
 * col -> type of card(2 to 9, 10-Joker, 11-Queen, 12-King, 13-Ace)
 */
vector<vector<int>> grid1(5, vector<int>(14, 0)), grid2(5, vector<int>(14, 0));
void init(){
    mp["straight flush"] = 1;
    mp["four of a kind"] = 2;
    mp["full house"] = 3;
    mp["flush"] = 4;
    mp["straight"] = 5;
    mp["three of a kind"] = 6;
    mp["two pairs"] = 7;
    mp["pair"] = 8;
    mp["high card"] = 9;
}
int findCardPos(char c){
    int pos = 0;
    switch (c)
    {
    case 'J':
    {
        pos = 10;
        break;
    }
    case 'Q':
    {
        pos = 11;
        break;
    }
    case 'K':
    {
        pos = 12;
        break;
    }
    default:
    {
        pos = 13;
        break;
    }
    }
    return pos;
}
pair<int, int> findPositionOfCard(string hand){
    int first = 0, second = 0;
    switch (hand[0])
    {
    case 'S':
    {
        first = 1;
        break;
    }
    case 'C':
    {
        first = 2;
        break;
    }
    case 'H':
    {
        first = 3;
        break;
    }
    // case 'D'
    default:
    {
        first = 4;
        break;
    }
    }

    if(hand[1] >= '2' and hand[1] <= '9')
        second = hand[1] - '0';
    else
        second = findCardPos(hand[1]);

    return {first, second};
}

int main(){
    string x, hand1, hand2;
    cin>>x;
    cin>>hand1;
    cin>>hand2;

    init();
    
    //mark all card of both hands in grid
    for(int i=0; i<hand1.size(); i+=3)
    {
        string h1 = hand1.substr(i, 2);
        string h2 = hand2.substr(i, 2);

        auto pos1 = findPositionOfCard(h1);
        auto pos2 = findPositionOfCard(h2);
        grid1[pos1.first][pos1.second] = 1;
        grid2[pos2.first][pos2.second] = 1;
    }
}



// cin>>str;
// string hand1 = str.substr(7, 14);
// string hand2 = str.substr(23);