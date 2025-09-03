#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> rank;

    for (int i = 0; i < players.size(); i++)
        rank[players[i]] = i;

    int idx;
    for (const auto& call : callings) {
        idx = rank[call];
        rank[call]--;
        rank[players[idx - 1]]++;
        swap(players[idx - 1], players[idx]);
    }
    return players;
}