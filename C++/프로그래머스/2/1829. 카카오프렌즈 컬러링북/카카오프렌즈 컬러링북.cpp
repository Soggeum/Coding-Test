#include <vector>
#include <unordered_set>

using namespace std;

struct Node
{
    int Val, Parent, Count;    
};

int GetParent(int i, vector<Node>& Table)
{
    if(Table[i].Parent == i)
    {
        return i;
    }
    return Table[i].Parent = GetParent(Table[i].Parent, Table);
}

void Merge(int i, int j, vector<Node>& Table)
{
    int ParentI = GetParent(i, Table);
    int ParentJ = GetParent(j, Table);
    if (ParentI == ParentJ)
    {
        return;
    }
    Table[ParentI].Count += Table[ParentJ].Count;
    Table[ParentJ].Parent = ParentI;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<Node> Table(m * n + 1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            Table[i * n + j].Val = picture[i][j];
            Table[i * n + j].Parent = i * n + j;
            Table[i * n + j].Count = 1;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j])
            {
                if (j && picture[i][j] == picture[i][j - 1])
                {
                    Merge(i * n + j, i * n + j - 1, Table);
                }
                if (i && picture[i][j] == picture[i - 1][j])
                {
                    Merge((i - 1) * n + j, i * n + j, Table);
                }
            }
        }
    }
    
    vector<int> answer = {0, 0};
    for (int i = 0;i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            if (picture[i][j])
            {
                if (Table[i * n + j].Parent == i * n + j)
                {
                    answer[0]++;
                    answer[1] = max(answer[1], Table[i * n + j].Count);
                }
            }
        }
    }
    
    return answer;
}