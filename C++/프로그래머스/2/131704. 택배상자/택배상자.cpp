#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    queue<int> belt;
    for (int i = 1; i <= order.size(); i++) {
        belt.push(i);
    }
    
    int idx = 0, answer = 0;
    stack<int> sub_belt;
    while (!belt.empty() || !sub_belt.empty()) {
        int target = order[idx];
        
        if (!belt.empty()) {
            if (target == belt.front()) {
                answer++;
                belt.pop();
                idx++;
            }
            else if (target > belt.front()) {
                sub_belt.push(belt.front());
                belt.pop();
            }
            else {
                if (target == sub_belt.top()) {
                    answer++;
                    sub_belt.pop();
                    idx++;
                }
                else {
                    return answer;
                }
            }
        }
        
        else {
            if (target == sub_belt.top()) {
                answer++;
                sub_belt.pop();
                idx++;
            }
            else {
                return answer;
            }
        }
    }
    return answer;
}