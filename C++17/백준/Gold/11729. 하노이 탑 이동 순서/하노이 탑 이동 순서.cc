#include <iostream>
#include <string>

using namespace std;

void solution(int N, int from, int to, string& answer, int& count) {
    if (N == 1) {
        answer += to_string(from) + " " + to_string(to) + "\n";
        count++;
        return;
    }
    int mid;
    for (int i = 1; i <= 3; i++) {
        if (i != from && i != to)
            mid = i;
    }
    solution(N - 1, from, mid, answer, count);
    answer += to_string(from) + " " + to_string(to) + "\n";
    count++;
    solution(N - 1, mid, to, answer, count);
}

int main() {
    int N;
    cin >> N;
    string answer;
    int count = 0;
    solution(N, 1, 3, answer, count);
    cout << count << endl;
    cout << answer;
    return 0;
}