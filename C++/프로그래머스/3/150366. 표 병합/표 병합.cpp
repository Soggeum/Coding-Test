#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Node
{
    int Parent;
    string Value;    
};

int GetParent(int Idx, vector<Node>& Table)
{
    if (Idx == Table[Idx].Parent)
    {
        return Idx;
    }
    return Table[Idx].Parent = GetParent(Table[Idx].Parent, Table);
}

string& GetValue(int Idx, vector<Node>& Table)
{
    int Parent = GetParent(Idx, Table);
    return Table[Parent].Value;
}

void Merge(int i1, int i2, vector<Node>& Table)
{
    int Parent1 = GetParent(i1, Table), Parent2 = GetParent(i2, Table);
    if (Parent1 == Parent2)
    {
        return;
    }
    string s1 = Table[Parent1].Value, s2 = Table[Parent2].Value;
    if (!s1.empty())
    {
        Table[Parent2].Parent = Parent1;
    }
    else
    {
        Table[Parent1].Parent = Parent2;
    }
}

vector<string> solution(vector<string> commands) {
    vector<Node> Table(50 * 50);
    for (int i = 0; i <Table.size(); i++)
    {
        Table[i].Parent = i;
    }
    
    vector<string> answer;
    for (const string& c : commands)
    {
        stringstream ss(c);
        string command;
        ss >> command;
        if (command == "UPDATE")
        {
            string a, b, c;
            ss >> a >> b >> c;
            if (c.empty())
            {
                for (int i = 0; i < Table.size(); i++)
                {
                    string& Value = GetValue(i, Table);
                    if (Value == a)
                    {
                        Value = b;
                    }
                }
            }
            else
            {
                int row = stoi(a), col = stoi(b);
                row--; col--;
                GetValue(row * 50 + col, Table) = c;
            }
        }
        else if (command == "MERGE")
        {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            Merge(r1 * 50 + c1, r2 * 50 + c2, Table);
        }
        else if (command == "UNMERGE")
        {
            int r, c;
            ss >> r >> c;
            r--; c--;
            string Value = GetValue(r * 50 + c, Table);
            int P = GetParent(r * 50 + c, Table);
            vector<int> Del;
            for (int i = 0; i < Table.size(); i++)
            {
                if (GetParent(i, Table) == P)
                {
                    Del.push_back(i);
                }
            }
            for (int i : Del)
            {
                Table[i].Parent = i;
                Table[i].Value.clear();
            }
            Table[r * 50 + c].Value = Value;
        }
        else
        {
            int r, c;
            ss >> r >> c;
            r--; c--;
            string& res = GetValue(r * 50 + c, Table);
            answer.push_back(res.empty() ? "EMPTY" : res);
        }
    }
    return answer;
}