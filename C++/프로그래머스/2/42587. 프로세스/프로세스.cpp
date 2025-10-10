#include <string>
#include <vector>
#include <queue>

// #include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    vector<int> cnt(9, 0);
    int max_priority = 0;
    for (int i = 0; i < priorities.size(); i++) {
        if (priorities[i] > max_priority)
            max_priority = priorities[i];
        cnt[priorities[i] - 1]++;
        q.push({i, priorities[i]});
    }
    
    int answer = 0;
    int top_loc, top_priority;
    while (1) {
        top_loc = q.front().first;
        top_priority = q.front().second;
        q.pop();
        
        if (top_priority < max_priority) {
            q.push({top_loc, top_priority});
        }
        
        else {
            answer++;
            if (top_loc == location) {
                return answer;
            }
            
            cnt[top_priority - 1]--;
            if (cnt[top_priority - 1] == 0) {
                for (int i = top_priority - 2; i >= 0; i--) {
                    if (cnt[i] > 0) {
                        max_priority = i + 1;
                        break;
                    }
                }
            }
        }
    }
    
    
    return 0;
}