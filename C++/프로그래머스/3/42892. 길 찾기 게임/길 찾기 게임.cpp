#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

struct TableNode
{
    int Num, X;
};

struct TreeNode
{
    int Num, X, Left, Right;
};

void ConnectToParent(vector<TreeNode>& Tree, int ChildX, int ChildIdx)
{
    int CurIdx = 0, NextIdx;
    while (1)
    {
        if (Tree[CurIdx].X < ChildX)
        {
            NextIdx = Tree[CurIdx].Right;
            if (NextIdx == -1)
            {
                Tree[CurIdx].Right = ChildIdx;
                return;
            }
        }
        else
        {
            NextIdx = Tree[CurIdx].Left;
            if (NextIdx == -1)
            {
                Tree[CurIdx].Left = ChildIdx;
                return;
            }
        }
        CurIdx = NextIdx;
    }
}
    
void TraversePre(vector<int>& PreOrder, const vector<TreeNode>& Tree, int Cur)
{
    if (Cur == -1)
    {
        return;
    }
    
    PreOrder.push_back(Tree[Cur].Num);
    TraversePre(PreOrder, Tree, Tree[Cur].Left);
    TraversePre(PreOrder, Tree, Tree[Cur].Right);
}

void TraversePost(vector<int>& PostOrder, const vector<TreeNode>& Tree, int Cur)
{
    if (Cur == -1)
    {
        return;
    }
    
    TraversePost(PostOrder, Tree, Tree[Cur].Left);
    TraversePost(PostOrder, Tree, Tree[Cur].Right);
    PostOrder.push_back(Tree[Cur].Num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    map<int, vector<TableNode>> Table;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        Table[nodeinfo[i][1]].push_back({i + 1, nodeinfo[i][0]});
    }
    
    vector<TreeNode> Tree;
    Tree.reserve(nodeinfo.size());
    auto it = Table.rbegin();
    Tree.push_back({it->second[0].Num, it->second[0].X, -1, -1});
    ++it;
    
    for (; it != Table.rend(); it++)
    {
        for (const TableNode& node : it->second)
        {
            Tree.push_back({node.Num, node.X, -1, -1});
            ConnectToParent(Tree, node.X, Tree.size() - 1);
        }
    }
    
    vector<vector<int>> answer;
    vector<int> PreOrder, PostOrder;
    PreOrder.reserve(nodeinfo.size());
    PostOrder.reserve(nodeinfo.size());
    
    TraversePre(PreOrder, Tree, 0);
    TraversePost(PostOrder, Tree, 0);
    
    answer.push_back(PreOrder);
    answer.push_back(PostOrder);
    return answer;
}