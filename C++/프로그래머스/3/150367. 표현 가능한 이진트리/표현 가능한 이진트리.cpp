#include <string>
#include <vector>

using namespace std;

string GetBin(long long n)
{
    string res;
    while (n)
    {
        if (n & 1)
        {
            res.push_back('1');
        }
        else
        {
            res.push_back('0');
        }
        n >>= 1;
    }
    
    int cnt = 1;
    while (cnt < res.size())
    {
        cnt = cnt * 2 + 1;
    }
    string CBT(cnt - res.size(), '0');
    CBT.append(string(res.rbegin(), res.rend()));
    return CBT;
}

bool IsCBT(const string& ns, int Root, int Left, int Right)
{
    if (Root == Left)
    {
        return true;
    }
    
    if (ns[Root] == '1')
    {
        return IsCBT(ns, (Left + Root - 1) / 2, Left, Root - 1) && IsCBT(ns, (Root + 1 + Right) / 2, Root + 1, Right);
    }
    else
    {
        for (int i = Left; i <= Right; i++)
        {
            if (ns[i] == '1')
            {
                return false;
            }
        }
        return true;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long n : numbers)
    {
        string ns = GetBin(n);
        if (IsCBT(ns, (ns.size() - 1) / 2, 0, ns.size() - 1))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}