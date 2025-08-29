#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, back;
    while (section.size()) {
        back = section.back();
        answer++;
        while ((section.size()) && (section.back() >= back - (m - 1)))
            section.pop_back();
    }
    return answer;
}