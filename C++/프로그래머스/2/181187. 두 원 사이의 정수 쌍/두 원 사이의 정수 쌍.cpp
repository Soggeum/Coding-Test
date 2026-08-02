#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (int x = -r2; x <= r2; x++)
    {
        long long y2 = sqrt(1ll*r2*r2 - 1ll*x*x);
        if (x <= -r1 || x >= r1)
        {
            answer += 2 * y2 + 1;
        }
        else
        {
            long long y1 = ceil(sqrt(1ll*r1*r1 - 1ll*x*x));
            answer += 2 * (y2 - y1 + 1);
        }
    }
    return answer;
}