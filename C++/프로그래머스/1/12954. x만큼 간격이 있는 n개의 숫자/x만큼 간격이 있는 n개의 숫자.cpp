#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    int start = x;
    vector<long long> answer;
    for (int i = 0; i < n; i++) {
        answer.push_back(start);
        start += x;
    }
    
    return answer;
}