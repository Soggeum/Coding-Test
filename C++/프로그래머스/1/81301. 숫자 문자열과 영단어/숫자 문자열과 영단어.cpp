#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string answer{};
    string temp{};
    map<string, int> table = { {"zero", 0},
                               { "one", 1},
    {"two", 2}, { "three", 3}, {"four", 4},
    { "five", 5}, {"six", 6}, { "seven", 7},
    {"eight", 8}, { "nine", 9}    };
    map<string, int>::iterator it;


    for (char c : s) {
        if (isdigit(c))
            answer.push_back(c);
        else
            temp.push_back(c);

        it = table.find(temp);
        if (it != table.end()) {
            answer.append(to_string(it->second));
            temp.clear();
        }
    }
    return stoi(answer);
}