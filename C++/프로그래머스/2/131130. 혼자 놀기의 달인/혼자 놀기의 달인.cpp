#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> cards) {
    priority_queue<int> pq;
    vector<bool> visit(cards.size(), false);
    for (int i = 0; i < cards.size(); i++) {
        if (visit[i] == true)
            continue;
        int cnt = 0, cur_idx = i;
        while (visit[cur_idx] == false) {
            cnt++;
            visit[cur_idx] = true;
            cur_idx = cards[cur_idx] - 1;
        }
        pq.push(cnt);
    }
    if (pq.size() < 2)
        return 0;
    int a = pq.top(); pq.pop();
    return a * pq.top();
}