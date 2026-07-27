#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string GetBin(long long n)
{
    string res;
    while (n)
    {
        res.push_back('0' + n % 2);
        n /= 2;
    }
    return string(res.rbegin(), res.rend());
}

bool IsCBT(const string& CBT, int Left, int Root, int Right)
{
    if (Left == Root && Root == Right)
    {
        return true;
    }
    
    if (CBT[Root] == '1')
    {
        return IsCBT(CBT, Left, (Left + Root - 1) / 2, Root - 1) && 
            IsCBT(CBT, Root + 1, (Root + 1 + Right) / 2, Right);
    }
    else
    {
        for (int i = Left; i <= Right; i++)
        {
            if (CBT[i] == '1')
            {
                return false;
            }
        }
        return true;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> CBT;
    int Num = 1;
    while (Num <= 64)
    {
        CBT.push_back(Num);
        Num = Num * 2 + 1;
    }
    
    vector<int> answer;
    for (long long number : numbers)
    {
        string Bin = GetBin(number);
        int CBTNum = *lower_bound(CBT.begin(), CBT.end(), Bin.size());
        string CBTBin(CBTNum - Bin.size(), '0');
        CBTBin.append(Bin);
        
        if (IsCBT(CBTBin, 0, (CBTBin.size() - 1) / 2, CBTBin.size() - 1))
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