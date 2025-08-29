#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> v1 {1, 2, 3, 4, 5};
    vector<int> v2 {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> answer_num (3, 0);
    for (int i = 0; i < answers.size(); i++) {
        if (v1[i % 5] == answers[i])
            answer_num[0]++;
        if (v2[i % 8] == answers[i])
            answer_num[1]++;
        if (v3[i % 10] == answers[i])
            answer_num[2]++;
    } 
    
    vector<int> result;
    int max = *max_element(answer_num.begin(), answer_num.end());
    for (int i = 0; i < answer_num.size(); i++) {
        if (answer_num[i] == max)
            result.push_back(i + 1);
    }
    
    return result;
}