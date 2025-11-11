#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sequence, int k) {
    int low = 0, high = 0, sum = sequence[0];
    int len = sequence.size();
    bool bCan = false;

    while (high < sequence.size()) {
        if (sum >= k) {
            bCan = true;
            len = (high - low + 1 < len) ? high - low + 1 : len;
            sum -= sequence[low++];
            if (low == sequence.size())
                break;
        }
        else {
            high++;
            if (high == sequence.size())
                break;
            sum += sequence[high];
        }
    }

    return bCan? len : 0;
}

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solution(A, M);
    return 0;
}