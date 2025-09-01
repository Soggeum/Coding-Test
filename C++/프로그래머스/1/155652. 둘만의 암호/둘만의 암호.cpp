#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    unordered_set<char> sk(skip.begin(), skip.end());
    
    for (char c: s) {
        for (int i = 0; i < index; ) {
            c = ((c == 'z') ? 'a': c + 1);
            if (sk.find(c) != sk.end())
                continue;
            i++;
        }
        answer.push_back(c);
    }
    return answer;
}