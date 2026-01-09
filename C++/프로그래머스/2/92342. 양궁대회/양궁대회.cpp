#include <string>
#include <vector>

using namespace std;

void Caculate(const vector<int>& info, const vector<int>& Lyan, vector<int>& answer, int& Gap)
{
    int ApeachScore = 0, LyanScore = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i] < Lyan[i])
        {
            LyanScore += (10 - i);
        }
        else 
        {
            if (info[i] > 0)
            {
                ApeachScore += (10 - i);
            }
        }
    }
    if (LyanScore - ApeachScore > Gap)
    {
        Gap = LyanScore - ApeachScore;
        answer = Lyan;
        return;
    }
    else if (Gap != 0 && LyanScore - ApeachScore == Gap)
    {
        for (int i = Lyan.size() - 1; i >= 0; i--)
        {
            if (Lyan[i] > answer[i])
            {
                answer = Lyan;
                return;
            }
            else if (Lyan[i] < answer[i])
            {
                return;
            }
        }
    }
}

void DFS(int n, const vector<int>& info, vector<int>& Lyan, int idx, vector<int>& answer, int& Gap)
{
    if (idx == 10)
    {
        Lyan[idx] = n;
        Caculate(info, Lyan, answer, Gap);
        return;
    }
    
    for (int i = 0; i <= n; i++)
    {
        Lyan[idx] = i;
        DFS(n - i, info, Lyan, idx + 1, answer, Gap);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> Lyan(11);
    vector<int> answer;
    int Gap = 0;
    DFS(n, info, Lyan, 0, answer, Gap);
    return (Gap == 0) ? vector<int>{-1} : answer;
}    