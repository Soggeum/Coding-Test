#include <string>
#include <vector>
#include <sstream>

#include <iostream>

using namespace std;

struct Node
{
    int Parent;
    string Value;
};

int GetIdx(int r, int c)
{
    return (r - 1) * 50 + c;
}

int GetParent(vector<Node>& Table, int i)
{
    if (Table[i].Parent == i)
    {
        return i;
    }
    return Table[i].Parent = GetParent(Table, Table[i].Parent);
}

vector<string> solution(vector<string> commands) {
    vector<Node> Table(2501);
    for (int i = 1; i < 2501; i++)
    {
        Table[i].Parent = i;
        Table[i].Value = "EMPTY";
    }
    
    vector<string> answer;
    for (const string& command : commands)
    {
        stringstream ss(command);
        string c;
        ss >> c;
        if (c == "UPDATE")
        {
            string a, b, value;
            ss >> a >> b >> value;
            if (value.empty())
            {
                for (int i = 1; i < Table.size(); i++)
                {
                    int Parent = GetParent(Table, i);
                    if (Table[Parent].Value == a)
                    {
                        Table[Parent].Value = b;
                    }
                }
            }
            else
            {
                int row = stoi(a), col = stoi(b);
                int Parent = GetParent(Table, GetIdx(row, col));
                Table[Parent].Value = value;
            }
        }
        else if (c == "MERGE")
        {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            int P1 = GetParent(Table, GetIdx(r1, c1));
            int P2 = GetParent(Table, GetIdx(r2, c2));
            if (P1 != P2)
            {
                string V1 = Table[P1].Value, V2 = Table[P2].Value, Value;
                Value = V1 == "EMPTY" ? V2 : V1;
                Table[P2].Parent = P1;
                Table[P1].Value = Value;
            }
        }
        else if (c == "UNMERGE")
        {
            int r, c;
            ss >> r >> c;
            int Parent = GetParent(Table, GetIdx(r, c));
            string Value = Table[Parent].Value;
            
            vector<int> Targets;
            for (int i = 1; i < Table.size(); i++)
            {
                int p = GetParent(Table, i);
                if (Table[p].Parent == Parent)
                {
                    Targets.push_back(i);
                }
            }
            for (int T : Targets)
            {
                Table[T].Parent = T;
                Table[T].Value = "EMPTY";
            }
            Table[(r - 1) * 50 + c].Value = Value;
        }
        else
        {
            int r, c;
            ss >> r >> c;
            int Parent = GetParent(Table, GetIdx(r, c));
            answer.push_back(Table[Parent].Value);
        }
    }
    
    return answer;
}