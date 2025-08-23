#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx{ 0 };

    for (int i = 0; i < s.size(); idx++, i++) {
        if (s[i] == ' ') {
			answer.push_back(' ');
            idx = -1;
        }
            
        else if (idx & 1)
            answer.push_back((s[i] >= 'a') ? (s[i]) : (s[i] - 'A' + 'a'));
        else
            answer.push_back((s[i] >= 'a') ? (s[i] - 'a' + 'A') : (s[i]));
    }

    return answer;
}