#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sequence, int k) {
    int low = 0, high = 0, cnt = 0;
    int sum = sequence[0];

    while (high < sequence.size()) {
        if (sum == k) {
            cnt++;
            sum -= sequence[low++];
        }
        else if (sum < k) {
            high++;
            if (high == sequence.size())
                break;
            sum += sequence[high];
        }
        else {
            sum -= sequence[low++];
        }
    }

    return cnt;
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