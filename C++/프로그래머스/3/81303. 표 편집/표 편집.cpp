#include <string>
#include <vector>

using namespace std;

struct Node
{
    int Prev, Next;    
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
    
    vector<int> Clear;
    for (const string& s : cmd)
    {
        if (s[0] == 'U')
        {
            int X = stoi(s.substr(2));
            while (X)
            {
                k = Table[k].Prev;
                X--;
            }
        }
        else if (s[0] == 'D')
        {
            int X = stoi(s.substr(2));
            while (X)
            {
                k = Table[k].Next;
                X--;
            }
        }
        else if (s[0] == 'C')
        {
            if (Table[k].Prev != -1)
            {
                Table[Table[k].Prev].Next = Table[k].Next;                
            }
            if (Table[k].Next != -1)
            {
                Table[Table[k].Next].Prev = Table[k].Prev;    
            }
            Clear.push_back(k);
            
            k = (Table[k].Next == -1 ? Table[k].Prev : Table[k].Next);
        }
        else
        {
            int ClearK = Clear.back();
            Clear.pop_back();
            
            if (Table[ClearK].Prev != -1)
            {
                Table[Table[ClearK].Prev].Next = ClearK;
            }
            if (Table[ClearK].Next != -1)
            {
                Table[Table[ClearK].Next].Prev = ClearK;
            }
        }
    }
    
    string answer(n, 'O');
    for (int i : Clear)
    {
        answer[i] = 'X';
    }
    return answer;
}