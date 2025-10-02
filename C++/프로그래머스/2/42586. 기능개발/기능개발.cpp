#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int date = ceil((100.0f - progresses[0]) / speeds[0]), cnt = 1;
    for (int i = 1; i < progresses.size(); i++) {
        if (progresses[i] + speeds[i] * date >= 100) {
            cnt++;
        }
        else {
            answer.push_back(cnt);
            cnt = 1;
            date = ceil((100.0f - progresses[i]) / speeds[i]);            
        }
    }
    
    if (cnt)
        answer.push_back(cnt);
    
    return answer;
}