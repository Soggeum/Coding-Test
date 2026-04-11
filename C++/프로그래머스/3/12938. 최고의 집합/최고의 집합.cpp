#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s)
    {
        return {-1};
    }
    
    while (s)
    {
        int num = s / (n - answer.size());
        s -= num;
        answer.push_back(num);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}