#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> count(2, 0);
    char x;
    for (int i = 0, j; i < s.length(); i = j + 1) {
        x = s[i];
        count[0] = 1;
        for (j = i + 1; j < s.length(); j++) {
            if (x == s[j])
                count[0]++;
            else
                count[1]++;
            
            if (count[0] == count[1]) {
                count[0] = count[1] = 0;
                break;
            }
        }
        answer++;
    }
    return answer;
}