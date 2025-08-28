#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (const int& a, const int& b) { return a > b;}

vector<int> solution(int k, vector<int> score) {
    vector<int> honor, answer;
    for (int x : score) {
        if (honor.size() < k) {
            honor.push_back(x);
            sort(honor.begin(), honor.end(), comp);
        }
        else if (x > honor.back()) {
            honor.pop_back();
            honor.push_back(x);
            sort(honor.begin(), honor.end(), comp);
        }
        
        answer.push_back(honor.back());
    }
    return answer;
}