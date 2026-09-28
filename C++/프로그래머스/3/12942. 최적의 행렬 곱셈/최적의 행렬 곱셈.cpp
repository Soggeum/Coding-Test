#include <string>
#include <vector>

using namespace std;

int Solve(vector<vector<int>>& DP, int Start, int End, const vector<vector<int>>& matrix_sizes)
{
    if (Start == End || DP[Start][End])
    {
        return DP[Start][End];
    }
    
    int Result = 123456789;
    for (int i = Start; i < End; i++)
    {
        int LeftCnt = Solve(DP, Start, i, matrix_sizes);
        int RightCnt = Solve(DP, i + 1, End, matrix_sizes);
        int Multiply = matrix_sizes[Start][0] * matrix_sizes[i][1] * matrix_sizes[End][1];
        Result = min(Result, LeftCnt + RightCnt + Multiply);
    }
    
    return DP[Start][End] = Result;
}

int solution(vector<vector<int>> matrix_sizes) {
    int N = matrix_sizes.size();
    vector<vector<int>> DP(N, vector<int>(N));
    return Solve(DP, 0, N - 1, matrix_sizes);
}