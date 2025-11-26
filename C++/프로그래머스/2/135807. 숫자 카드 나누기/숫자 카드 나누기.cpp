#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    
    return GCD(b, a % b);
}

int GCDs(const vector<int>& array) {
    int gcd = array[0];
    for (int i = 1; i < array.size(); i++) {
        gcd = GCD(gcd, array[i]);
    }
    return gcd;
}

int Check(int gcd, const vector<int>& array) {
    for (int num : array) {
        if (num % gcd == 0) {
            return 0;
        }
    }
    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int GCDA = GCDs(arrayA), GCDB = GCDs(arrayB);
    int Aa = Check(GCDA, arrayB), Ba = Check(GCDB, arrayA);

    return max(Aa, Ba);
}