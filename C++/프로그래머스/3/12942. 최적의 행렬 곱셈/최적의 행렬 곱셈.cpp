#include <string>
#include <vector>

using namespace std;

int Solve(int Start, int End, vector<vector<int>>& DP, const vector<vector<int>>& matrix_sizes)
{
    if (DP[Start][End] != 2100000000)
    {
        return DP[Start][End];
    }
    if (Start == End)
    {
        DP[Start][End] = 0;
        return DP[Start][End];
    }
    
    for (int i = Start; i < End; i++)
    {
        int Cost = Solve(Start, i, DP, matrix_sizes);
        Cost += Solve(i + 1, End, DP, matrix_sizes);
        Cost += matrix_sizes[Start][0] * matrix_sizes[i][1] * matrix_sizes[End][1];
        DP[Start][End] = min(DP[Start][End], Cost);
    }
    
    return DP[Start][End];
}

int solution(vector<vector<int>> matrix_sizes) {
    int N = matrix_sizes.size();
    vector<vector<int>> DP(N, vector<int>(N, 2100000000));
    return Solve(0, N - 1, DP, matrix_sizes);
}