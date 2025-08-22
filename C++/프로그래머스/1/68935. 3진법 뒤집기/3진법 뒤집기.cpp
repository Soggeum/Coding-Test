#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer{};
    string str{};
    while (n) {
        str.append(to_string(n % 3));
        n /= 3;
    }

    for (auto it = str.rbegin(); it != str.rend(); it++) {
        answer += (*it - '0') * pow(3, it - str.rbegin());
    }
    return answer;
}