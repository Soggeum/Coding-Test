#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(vector<int> arr) {
    int a = 1;
    int gcd;
    for (int x : arr) {
        gcd = GCD(a, x) ;
        a = (a / gcd) * x;
    }
    return a;
}