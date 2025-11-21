#include <string>
#include <vector>

using namespace std;

bool IsIn(long long row, long long col, long long d) {
    return row*row + col*col <= d*d;
}

long long solution(int k, int d) {
    long long answer = 0;
    long long row = 0, col = d / k * k;
    for (; row <= d ; row += k) {
        for(; col >= 0; col -= k) {
            if (IsIn(row, col, d)) {
                answer += col / k + 1;
                break;
            }     
        }
    }
    return answer;
}