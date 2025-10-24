#include <vector>
#include <iostream>

using namespace std;

bool IsAllSame(const vector<vector<int>>& arr, int row, int col, int num) {
    for (int i = row; i < row + num; i++) {
        for (int j = col; j < col + num; j++) {
            if (arr[i][j] != arr[row][col])
                return false;
        }
    }
    return true;
}

vector<int> solution(const vector<vector<int>>& arr, int row, int col, int num) {
    vector<int> result(3, 0);
    if (IsAllSame(arr, row, col, num)) {
        result[arr[row][col] + 1] = 1;
        return result;
    }

    vector<int> TL = solution(arr, row, col, num / 3);
    vector<int> TM = solution(arr, row, col + num / 3, num / 3);
    vector<int> TR = solution(arr, row, col + num / 3 * 2, num / 3);

    vector<int> ML = solution(arr, row + num / 3, col, num / 3);
    vector<int> MM = solution(arr, row + num / 3, col + num / 3, num / 3);
    vector<int> MR = solution(arr, row + num / 3, col + num / 3 * 2, num / 3);

    vector<int> BL = solution(arr, row + num / 3 * 2, col, num / 3);
    vector<int> BM = solution(arr, row + num / 3 * 2, col + num / 3, num / 3);
    vector<int> BR = solution(arr, row + num / 3 * 2, col + num / 3 * 2, num / 3);

    for (int i = 0; i < 3; i++) {
        result[i] += TL[i] + TM[i] + TR[i] + ML[i] + MM[i] + MR[i] + BL[i] + BM[i] + BR[i];
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> answer = solution(arr, 0, 0, N);
    for (int num : answer)
        cout << num << endl;
    return 0;
}