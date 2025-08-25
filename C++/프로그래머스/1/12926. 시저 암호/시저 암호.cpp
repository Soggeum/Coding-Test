#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char c : s) {
        if (c == ' ')
            answer.push_back(c);
        else if (c == toupper(c)) 
            answer.push_back((c + n > 'Z')? (c + n - 'Z' + 'A' - 1): (c + n));
        else
            answer.push_back((c + n > 'z')? (c + n - 'z' + 'a' - 1): (c + n));
    }
    return answer;
}