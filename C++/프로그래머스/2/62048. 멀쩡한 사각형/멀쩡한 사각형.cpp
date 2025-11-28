#include <cmath>

using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

long long solution(int w,int h) {
    long long answer = static_cast<long long>(w) * h;
    long long cut = (long long)w + h - GCD(w, h);
    return answer - cut;
}