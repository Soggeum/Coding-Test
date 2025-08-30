#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct = 0;
    int zero_count = count(lottos.begin(), lottos.end(), 0);
    unordered_set<int> set_lottos (lottos.begin(), lottos.end());
    
    for (int num : win_nums) {
        if (set_lottos.find(num) != set_lottos.end())
            correct++;
    }
    
    answer.push_back( (correct + zero_count > 1) ? (7 - correct - zero_count) : 6);
    answer.push_back( (correct > 1) ? (7 - correct) : 6);
    return answer;
}