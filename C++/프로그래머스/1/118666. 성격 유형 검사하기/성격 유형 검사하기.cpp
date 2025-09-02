#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<string, int> mbti = { {"RT", 0}, {"CF", 0}, {"JM", 0}, {"AN", 0} };
    string answer = "";

    unordered_map<string, int>::iterator it;
    for (int i = 0; i < choices.size(); i++) {
        it = mbti.find(survey[i]);
        if (it != mbti.end()) {
            it->second += choices[i] - 4;
        }
        else {
            mbti[string(survey[i].rbegin(), survey[i].rend())] -= choices[i] - 4;
        }
    }

    answer.push_back(mbti["RT"] <= 0 ? 'R' : 'T');
    answer.push_back(mbti["CF"] <= 0 ? 'C' : 'F');
	answer.push_back(mbti["JM"] <= 0 ? 'J' : 'M');
	answer.push_back(mbti["AN"] <= 0 ? 'A' : 'N');
    return answer;
}