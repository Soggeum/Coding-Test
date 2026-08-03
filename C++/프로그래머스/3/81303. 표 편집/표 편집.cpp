#include <string>
#include <vector>

using namespace std;

struct Node
{
    int Prev, Next;
};

struct SNode
{
    int Idx;
    Node node;
};

string solution(int n, int k, vector<string> cmd) {
    vector<Node> Table(n);
    Table[0] = {-1, 1};
    for (int i = 1; i < n - 1; i++)
    {
        Table[i].Prev = i - 1;
        Table[i].Next = i + 1;
    }
    Table[n - 1] = {n - 2, -1};
    
    vector<SNode> Stack;
    for (const string& c : cmd)
    {
        if (c[0] == 'U')
        {
            int X = stoi(c.substr(2));
            for (int i = 0; i < X; i++)
            {
                k = Table[k].Prev;
            }
        }
        else if (c[0] == 'D')
        {
            int X = stoi(c.substr(2));
            for (int i = 0; i < X; i++)
            {
                k = Table[k].Next;
            }
        }
        else if (c[0] == 'C')
        {
            Stack.push_back({k, Table[k]});
            if (Table[k].Prev != -1)
            {
                Table[Table[k].Prev].Next = Table[k].Next;
            }
            if (Table[k].Next != - 1)
            {
                Table[Table[k].Next].Prev = Table[k].Prev;
            }
            
            if (Table[k].Next == -1)
            {
                k = Table[k].Prev;
            }
            else
            {
                k = Table[k].Next;
            }
        }
        else
        {
            int Idx = Stack.back().Idx;
            Node node = Stack.back().node;
            Stack.pop_back();
            
            if (node.Prev != -1)
            {
                Table[node.Prev].Next = Idx;
            }
            if (node.Next != -1)
            {
                Table[node.Next].Prev = Idx;
            }
        }
    }
    
    string answer(n, 'O');
    while (!Stack.empty())
    {
        answer[Stack.back().Idx] = 'X';
        Stack.pop_back();
    }
    return answer;
}