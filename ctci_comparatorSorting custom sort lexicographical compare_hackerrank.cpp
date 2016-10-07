#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool mycompare(const Player & p1, const Player & p2){
    if(p1.score != p2.score) return p1.score > p2.score;
    return std::lexicographical_compare(p1.name.begin(), p1.name.end(), 
                                       p2.name.begin(), p2.name.end());
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), mycompare);
    return players;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
