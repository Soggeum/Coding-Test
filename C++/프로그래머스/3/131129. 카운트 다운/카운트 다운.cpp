#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int ThrowCount = 100001;
    int Single;
    int Bull;    
};

bool IsElse(int n)
{
    for (int i = 7; i <= 20; i++)
    {
        if (i * 2 == n || i * 3 == n)
        {
            return true;
        }
    }
    return false;
}

vector<int> solution(int target) {
    unordered_map<string, vector<int>> DartTable;
    DartTable["Single"] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    DartTable["Bull"] = {50};
    for (int i = 21; i <= 60; i++)
    {
        if (IsElse(i))
        {
            DartTable["Else"].push_back(i);
        }
    }
    
    vector<Node> DP(100001);
    for (int i : DartTable["Single"])
    {
        DP[i] = {1, 1, 0};
    }
    if (target >= 50)
    {
        DP[50] = {1, 0, 1};
    }
    for (int i : DartTable["Else"])
    {
        if (i >= DP.size())
        {
            break;
        }
        DP[i] = {1, 0, 0};
    }
    
    for (int i = 1; i <= target; i++)
    {
        for (int j : DartTable["Single"])
        {
            if (i + j > target)
            {
                break;
            }
            
            Node NewNode = {DP[i].ThrowCount + 1, DP[i].Single + 1, DP[i].Bull};
            if (NewNode.ThrowCount < DP[i + j].ThrowCount)
            {
                DP[i + j] = NewNode;
            }
            else if (NewNode.ThrowCount == DP[i + j].ThrowCount && NewNode.Single + NewNode.Bull > DP[i + j].Single + DP[i + j].Bull)
            {
                DP[i + j] = NewNode;
            }
        }
        
        for (int j : DartTable["Bull"])
        {
            if (i + j > target)
            {
                break;
            }
            
            Node NewNode = {DP[i].ThrowCount + 1, DP[i].Single, DP[i].Bull + 1};
            if (NewNode.ThrowCount < DP[i + j].ThrowCount)
            {
                DP[i + j] = NewNode;
            }
            else if (NewNode.ThrowCount == DP[i + j].ThrowCount && NewNode.Single + NewNode.Bull > DP[i + j].Single + DP[i + j].Bull)
            {
                DP[i + j] = NewNode;
            }
        }
        
        for (int j : DartTable["Else"])
        {
            if (i + j > target)
            {
                break;
            }
            
            Node NewNode = {DP[i].ThrowCount + 1, DP[i].Single, DP[i].Bull};
            if (NewNode.ThrowCount < DP[i + j].ThrowCount)
            {
                DP[i + j] = NewNode;
            }
            else if (NewNode.ThrowCount == DP[i + j].ThrowCount && NewNode.Single + NewNode.Bull > DP[i + j].Single + DP[i + j].Bull)
            {
                DP[i + j] = NewNode;
            }
        }
    }
    
    return {DP[target].ThrowCount, DP[target].Single + DP[target].Bull};
}