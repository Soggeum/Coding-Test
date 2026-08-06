#include <string>
#include <vector>

using namespace std;

string GetBin(long long n)
{
    string res;
    while (n)
    {
        res.push_back((n & 1) + '0');
        n >>= 1;
    }
    return string(res.rbegin(), res.rend());
}

bool IsTree(const string& s, int left, int root, int right)
{
    if (left == root && right == root)
    {
        return true;
    }
    if (s[root] == '1')
    {
        if (IsTree(s, left, (left + root - 1) / 2, root - 1) && IsTree(s, root + 1, (root + 1 + right) / 2, right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            if (s[i] == '1')
            {
                return false;
            }
        }
        return true;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long number : numbers)
    {
        string Bin = GetBin(number);
        int i = 1;
        while (i < Bin.size())
        {
            i = 2 * i + 1;
        }
        string s(i - Bin.size(), '0');
        s.append(Bin);
        
        if (IsTree(s, 0, i / 2, i - 1))
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