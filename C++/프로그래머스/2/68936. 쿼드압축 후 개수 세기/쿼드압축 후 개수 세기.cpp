#include <string>
#include <vector>

using namespace std;

int IsAllSame(const vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i][j] != arr[0][0]) {
                return -1;
            }
        }
    }    
    return arr[0][0];
}

vector<int> solution(vector<vector<int>> arr) {
    int result = IsAllSame(arr);
    if (result == 0) {
        return vector<int>{1, 0};
    }
    else if (result == 1) {
        return vector<int>{0, 1};
    }
    
    int mid = arr.size() / 2;
    vector<vector<int>> TopLeft;
    vector<vector<int>> TopRight;
    vector<vector<int>> BottomLeft;
    vector<vector<int>> BottomRight;
    for (int i = 0; i < mid; i++) {
        TopLeft.push_back(vector<int>(arr[i].begin(), arr[i].begin() + mid));
        TopRight.push_back(vector<int>(arr[i].begin() + mid, arr[i].end()));
        BottomLeft.push_back(vector<int>(arr[i + mid].begin(), arr[i + mid].begin() + mid));
        BottomRight.push_back(vector<int>(arr[i + mid].begin() + mid, arr[i + mid].end()));
    }
    
    vector<int> TL = solution(TopLeft);
    vector<int> TR = solution(TopRight);
    vector<int> BL = solution(BottomLeft);
    vector<int> BR = solution(BottomRight);
    
    vector<int> answer(2, 0);
    for (int i = 0; i < 2; i++) {
        answer[i] += TL[i] + TR[i] + BL[i] + BR[i];
    }
    return answer;
}