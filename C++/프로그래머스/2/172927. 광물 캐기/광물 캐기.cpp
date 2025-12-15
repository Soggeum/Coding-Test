#include <string>
#include <vector>

using namespace std;

int DFS(vector<int>& picks, int pick, const vector<string>& minerals, int idx, const vector<vector<int>>& table) {
    int Pirodo = 0, duration = 5, answer = 999999999, result = answer;
    while (duration > 0 && idx < minerals.size()) {
        if (minerals[idx] == "diamond") {
            Pirodo += table[pick][0];
        }
        else if (minerals[idx] == "iron") {
            Pirodo += table[pick][1];
        }
        else {
            Pirodo += table[pick][2];
        }
        --duration;
        ++idx;
    }
    
    if (idx == minerals.size())
        return Pirodo;
    
    for (int i = 0; i < picks.size(); ++i) {
        if (picks[i] > 0) {
            picks[i]--;
            result = DFS(picks, i, minerals, idx, table);
            answer = answer > result ? result : answer;
            picks[i]++;
        }       
    }
    
    if (answer == 999999999)
        return Pirodo;
    
    return Pirodo + answer;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 999999999, result = answer;
    vector<vector<int>> table = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
    
    for (int i = 0; i < picks.size(); ++i) {
        if (picks[i] > 0) {
            picks[i]--;
            result = DFS(picks, i, minerals, 0, table);
            answer = answer > result ? result : answer;
            picks[i]++;
        }       
    }
    
    return answer;
}