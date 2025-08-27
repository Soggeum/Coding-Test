#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, new_coke;
    while (n >= a) {
        new_coke = (n / a) * b;
        answer += new_coke;
        n = n % a + new_coke;   
    }
    return answer;
}