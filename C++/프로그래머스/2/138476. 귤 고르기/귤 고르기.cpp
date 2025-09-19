#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // {크기, 개수}
    unordered_map<int, int> table;
    for (const auto& x : tangerine) {
        table[x]++;
    }
    
    // {개수, 크기}. 최대힙
    priority_queue<pair<int, int>> q;
    for (auto& [size, cnt] : table) {
        q.push({cnt, size});
    }
    
    int cnt;
    while (k > 0) {
        cnt = q.top().first;
        q.pop();
        k -= cnt;
        answer++;
    }
    
    return answer;
}