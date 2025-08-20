#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (auto it = arr.begin(); it != arr.end(); it++) {
        if (!((*it) % divisor))
            answer.push_back(*it);        
    }
    
    sort(answer.begin(), answer.end());
    if (!(answer.size()))
        answer.push_back(-1);
    
    return answer;
}