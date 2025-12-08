#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    unordered_map<int, int> um;
    for (int w : weights) {
        um[w]++;
    }
    
    long long answer = 0;
    vector<int> numerator = {2, 1, 3, 3, 4, 2};
    vector<int> denominator = {3, 2, 2, 4, 3, 1};
    for (int w : weights) {
        answer += um[w] - 1;
        for (int i = 0; i < numerator.size(); ++i) {
            if (w % denominator[i] == 0) {
                answer += um[w * numerator[i] / denominator[i]];
            }
        }
    }
    
    return answer / 2;
}