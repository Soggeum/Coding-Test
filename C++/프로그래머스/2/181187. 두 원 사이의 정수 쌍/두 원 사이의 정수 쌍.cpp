#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long Caculate(double a, double b) {
    if (b == 0)
        return floor(a) * 2LL + 1;
    
    long long A = floor(a);  // ✅ 명시적 floor
    long long B = ceil(b);   // ✅ 명시적 ceil
    
    return (A - B + 1) * 2LL;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    for (int i = -r2; i <= r2; ++i) {
        long long ii = 1LL * i * i;
        long long r1sq = 1LL * r1 * r1;
        long long r2sq = 1LL * r2 * r2;
        
        if (ii > r1sq) {
            answer += Caculate(sqrt(r2sq - ii), 0);
        } else {
            answer += Caculate(sqrt(r2sq - ii), sqrt(r1sq - ii));
        }
    }
    return answer;
}