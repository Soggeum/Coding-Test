#include <string>
#include <vector>
#include <cmath>

using namespace std;

    int IsPressUp(const int FrontFront, const int c, int& answer) {
        if (c == 5) {
            answer += 5;
            return FrontFront >= 5;
        }
        
        int PressDown = c;
        int PressUp = 10 - c;
        if (PressDown <= PressUp) {
            answer += PressDown;
            return false;
        }
        
        answer += PressUp;
        return true;
    }

int solution(int storey) {
    int answer = 0;
    for (int i = 1; i <= 9; i++) {
        int cur = storey % static_cast<int>(pow(10, i));
        int Front = cur / pow(10, i - 1);
        int FrontFront = (storey % static_cast<int>(pow(10, i + 1))) / pow(10, i);
        if (IsPressUp(FrontFront, Front, answer)) {
            storey += pow(10, i);
        }
        storey -= cur;
    }

    return answer;
}