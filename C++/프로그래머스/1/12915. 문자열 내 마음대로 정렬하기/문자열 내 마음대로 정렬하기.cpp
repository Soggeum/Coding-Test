#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    string temp;
    for (int i = 0; i < answer.size() - 1; i++) {
        for (int j = 0; j < answer.size() - (i + 1); j++) {
            if (answer[j][n] > answer[j + 1][n]) {
                temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
            
            else if (answer[j][n] == answer[j + 1][n]) {
                if (answer[j] > answer[j + 1]) {
                    temp = answer[j];
                    answer[j] = answer[j + 1];
                    answer[j + 1] = temp;
                }
            }
        }
    }
    return answer;
}