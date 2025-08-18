#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    double dNum1 = num1;
    return (int)(dNum1 / num2 * 1000);
}