#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string MakeBinary(long long number)
{
    string Result;
    int R;
    while (number)
    {
        R = number % 2;
        Result.push_back('0' + R);
        number /= 2;
    }
    return string(Result.rbegin(), Result.rend());
}

bool IsRoot(string Binary, int root, bool OneFlag, const unordered_set<long long>& TwoPowers)
{
    if (!OneFlag && Binary[root] == '1')
    {
        return false;
    }
    OneFlag = Binary[root] == '1' ? true : false;
    
    if (Binary.size() == 1)
    {
        return true;
    }
    
        
    int RightChildNum = Binary.size() - 1 - root;
    if (TwoPowers.find(RightChildNum + 1) == TwoPowers.end())
    {
        return false;
    }
    
    string Left, Right = Binary.substr(root + 1);    
    if (root < Right.size())
    {
        Left.append(string(Right.size() - root, '0'));
    }
    Left.append(Binary.substr(0, root));
    
    int LeftRoot = Left.size() / 2, RightRoot = Right.size() / 2;
    
    bool bLeftCBT = IsRoot(Left, LeftRoot, OneFlag, TwoPowers);
    bool bRightCBT = IsRoot(Right, RightRoot, OneFlag, TwoPowers);
    return bLeftCBT && bRightCBT;
}

bool IsCBT(string Binary, const unordered_set<long long>& TwoPowers)
{
    for (int i = 0; i < (Binary.size() + 1) / 2; i++)
    {
        if (Binary[i] && IsRoot(Binary, i, true, TwoPowers))
        {
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<long long> numbers) {
    unordered_set<long long> TwoPowers;
    for (long long Temp = 1, Power = 0; Power < 60; Power++)
    {
        Temp *= 2;
        TwoPowers.insert(Temp);
    }    
    
    vector<int> answer;
    for (long long number : numbers)
    {
        string Binary = MakeBinary(number);
        if (IsCBT(Binary, TwoPowers))
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