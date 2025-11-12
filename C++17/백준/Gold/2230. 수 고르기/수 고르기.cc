#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    int low = 0, high = 0, Minus, MinMinus = 2000000000;
    while (high < N) {
        Minus = A[high] - A[low];
        if (Minus == M) {
            cout << M;
            return 0;
        }

        if (Minus > M) {
            MinMinus = Minus < MinMinus ? Minus : MinMinus;
            low++;
            if (low == high) {
                high++;
                if (high == N)
                    break;
            }
       
        }
        else {
            high++;
            if (high == N)
                break;
        }
    }

    cout << MinMinus;
    return 0;
}