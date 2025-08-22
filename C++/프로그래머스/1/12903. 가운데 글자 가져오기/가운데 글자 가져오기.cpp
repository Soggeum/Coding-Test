#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if (s.size() & 1)
        return string(s, s.size() / 2, 1);

    else
        return string(s, s.size() / 2 - 1, 2);
}