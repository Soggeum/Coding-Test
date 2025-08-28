#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    while(1) {
        if (goal.empty())
            return "Yes";
        if (cards1.empty()) {
            if (cards2 == goal)
                return "Yes";
            return "No";
        }
        if (cards2.empty()) {
            if (cards1 == goal)
                return "Yes";
            return "No";
        }
        
        if (cards1.front() == goal.front()) {
            cards1.erase(cards1.begin());
            goal.erase(goal.begin());
            continue;
        }
            
        else if (cards2.front() == goal.front()) {
            cards2.erase(cards2.begin());
            goal.erase(goal.begin());
            continue;
        }
        
        return "No";
    }
}