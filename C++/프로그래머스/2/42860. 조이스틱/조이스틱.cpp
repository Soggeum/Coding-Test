#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();

    for (int i = 0; i < len; ++i) {
        char ch = name[i];
        int up = ch - 'A';
        int down = 'Z' - ch + 1;
        answer += min(up, down);
    }

    int move = len - 1; 
    for (int i = 0; i < len; ++i) {
        int next = i + 1;
        while (next < len && name[next] == 'A') next++;

        int option1 = i * 2 + (len - next);
        int option2 = i + 2 * (len - next);
        move = min(move, min(option1, option2));
    }

    return answer + move;
}
