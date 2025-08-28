#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end());    
    int answer = 0;
    
    for (auto rit = score.rbegin() + m - 1; rit < score.rend(); rit += m)
        answer += *rit * m;        
    return answer;
}