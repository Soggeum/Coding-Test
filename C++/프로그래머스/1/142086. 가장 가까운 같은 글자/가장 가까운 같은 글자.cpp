#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string::reverse_iterator it;
    string::reverse_iterator s_rit;
    for (auto s_it = s.begin(); s_it != s.end(); s_it++) {
        s_rit = make_reverse_iterator(s_it);
        it = find(s_rit, s.rend(), *s_it);
        answer.push_back((it == s.rend()) ? -1 : it - s_rit + 1);
    }
    return answer;
}