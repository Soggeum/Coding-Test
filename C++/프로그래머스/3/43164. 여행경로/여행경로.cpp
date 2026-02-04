#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

void DFS(vector<string>& answer, unordered_map<string, list<string>>& Table, int n, bool& bIsFinished)
{
    if (answer.size() == n) {
        bIsFinished = true;
        return;
    }

    string start = answer.back();
    auto& destList = Table[start];

    for (auto it = destList.begin(); it != destList.end(); ) {
        string dest = *it;
        it = destList.erase(it); 
        answer.push_back(dest);

        DFS(answer, Table, n, bIsFinished);

        if (bIsFinished) return;
        
        answer.pop_back();
        destList.insert(it, dest); 
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    unordered_map<string, list<string>> Table;
    for (const auto& t : tickets) {
        Table[t[0]].push_back(t[1]);
    }

    vector<string> answer = {"ICN"};
    bool bIsFinished = false;
    DFS(answer, Table, tickets.size() + 1, bIsFinished);

    return answer;
}