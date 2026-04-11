#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsCode(const vector<int>& Comb, const vector<vector<int>>& q, const vector<int>& ans)
{
    for (int i = 0; i < q.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (find(Comb.begin(), Comb.end(), q[i][j]) != Comb.end())
            {
                cnt++;
            }
        }
        if (cnt != ans[i])
        {
            return false;
        }
    }
    return true;
}

void DFS(int start, vector<int>& Comb, const int& n, const vector<vector<int>>& q, const vector<int>& ans, int& answer)
{
    if (Comb.size() == 5)
    {
        if (IsCode(Comb, q, ans))
        {
            answer++;
        }
        return;
    }
    
    for (; start <= n + Comb.size() - 4; start++)
    {
        Comb.push_back(start);
        DFS(start + 1, Comb, n, q, ans, answer);
        Comb.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> Comb;
    DFS(1, Comb, n, q, ans, answer);    
    return answer;
}