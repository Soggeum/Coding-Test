#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    if (!n)
        return n;
    
    int answer = 0, i = 1;
    for (; i < sqrt(n); i++) {
        if (!(n % i)) {
            answer += i;
            answer += n / i;
        }
    }
    
    if (!(n % i))
        answer += i;
    
    return answer;
}