#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

vector<int> solution(int n, int m) {    
    return vector<int>{gcd(n, m), gcd(n, m) * (n / gcd(n, m)) * (m / gcd(n, m))};
}