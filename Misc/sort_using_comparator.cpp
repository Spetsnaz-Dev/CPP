// //Given an array of n Player objects, write a comparator that sorts
//  them in order of decreasing score. If or more players have the same 
//  score, sort those players alphabetically ascending by name. To do this,
//   you must create a Checker class that implements the Comparator interface,
//    then write an int compare(Player a, Player b) method implementing the 
//    Comparator.compare(T o1, T o2) method. In short, when sorting in ascending
//     order, a comparator function returns -1 if a<b , 0 if a=b, 1 if a>b
//SAMPLE INPUT 
// 5
// amy 100
// david 100
// heraldo 50
// aakansha 75
// aleksa 150

// SAMPLE OUTPUT
// aleksa 150
// amy 100
// david 100
// aakansha 75
// heraldo 50

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if (a.score > b.score) return 1 ;
        if (a.score < b.score) return -1 ;
        if (a.name > b.name) return -1 ;
        if (a.name < b.name) return 1 ;
    return 0;
    }
};

bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}