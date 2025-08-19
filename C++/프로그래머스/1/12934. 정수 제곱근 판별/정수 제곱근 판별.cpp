#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double x {sqrt(n)};
    
    return (x == static_cast<int>(x)) ? pow(x + 1, 2) : -1;
}