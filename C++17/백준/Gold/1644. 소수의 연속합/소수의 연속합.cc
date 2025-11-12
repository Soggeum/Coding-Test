#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(int n) {
    if (n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> MakePrimeArr(int N) {
    vector<int> result;

    for (int i = 2; i <= N; i++) {
        if (IsPrime(i))
            result.push_back(i);
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    vector<int> PrimeArr = MakePrimeArr(N);
    int low = 0, high = 0, sum = PrimeArr[0], answer = 0;

    while (high < PrimeArr.size()) {
        if (sum == N) {
            answer++;
            sum -= PrimeArr[low++];
            if (low == PrimeArr.size())
                break;
        }
        else if (sum < N) {
            high++;
            if (high == PrimeArr.size())
                break;
            sum += PrimeArr[high];
        }
        else {
            sum -= PrimeArr[low++];
            if (low == PrimeArr.size())
                break;
        }
    }
    
    cout << answer;
    return 0;
}