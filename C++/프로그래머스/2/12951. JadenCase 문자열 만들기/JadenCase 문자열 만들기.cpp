#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for (char c : s) {
        if (flag) {
            if (isalnum(c))
                flag = false;
            answer.push_back(toupper(c));
        }
        else {
            answer.push_back(tolower(c));
            if (c == ' ')
                flag = true;
        }
    }
    return answer;
}