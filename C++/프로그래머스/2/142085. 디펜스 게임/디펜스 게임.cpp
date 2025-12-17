#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++) {
        q.push({enemy[i]});
    }
    
    for (int i = k; i < enemy.size(); ++i) {
        if (q.top() < enemy[i]) {
            n -= q.top(); q.pop();
            q.push(enemy[i]);
        }
        else {
            n -= enemy[i];
        }
        if (n < 0) return i;
    }
    
    return enemy.size();
}