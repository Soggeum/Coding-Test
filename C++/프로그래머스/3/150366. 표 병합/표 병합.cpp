#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Cell
{
    string Value;
    Cell* Parent;
    
    Cell* Merge(Cell* NewParent)
    {
        if (Parent == this)
        {
            Parent = NewParent;
            return Parent;
        }
        return Parent = Parent->Merge(NewParent);
    }
    
    Cell* GetParent()
    {
        if (Parent == this)
        {
            return Parent;
        }
        return Parent = Parent->GetParent();
    }
    
    string GetValue()
    {
        if (Parent == this)
        {
            return Value;
        }
        return GetParent()->GetValue();
    }
};

vector<string> solution(vector<string> commands) {
    vector<vector<Cell>> Table(50, vector<Cell>(50));
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            Table[i][j].Parent = &(Table[i][j]);
        }
    }
    
    vector<string> answer;
    for (const string& command : commands)
    {
        string SplitCommand, Value1, Value2;
        int r1, r2, c1, c2;
        
        if (command[0] == 'P')
        {
            stringstream ss(command);
            ss >> SplitCommand >> r1 >> c1;
            r1--; c1--;
            string Value = Table[r1][c1].GetValue();
            answer.push_back(Value.empty() ? "EMPTY" : Value);
        }
        else if (command.substr(0, 2) == "UP")
        {
            stringstream ss(command);
            string a, b, c;
            ss >> SplitCommand >> a >> b >> c;
            if (c.empty())
            {
                Value1 = a;
                Value2 = b;
                for (vector<Cell>& row : Table)
                {
                    for (Cell& cell : row)
                    {
                        if (cell.GetValue() == Value1)
                        {
                            cell.GetParent()->Value = Value2;
                        }
                    }
                }
            }
            else
            {
                r1 = stoi(a);
                c1 = stoi(b);
                r1--; c1--;
                Value1 = c;
                Table[r1][c1].GetParent()->Value = Value1;
            }
        }
        else if (command[0] == 'M')
        {
            stringstream ss(command);
            ss >> SplitCommand >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            if (!(Table[r1][c1].GetValue().empty()))
            {
                Table[r2][c2].GetParent()->Merge(Table[r1][c1].GetParent());
            }
            else
            {
               Table[r1][c1].GetParent()->Merge(Table[r2][c2].GetParent());
            }
        }
        else
        {
            stringstream ss(command);
            ss >> SplitCommand >> r1 >> c1;
            r1--; c1--;
            Cell* Parent = Table[r1][c1].GetParent();
            string Value = Parent->GetValue();
            vector<Cell*> Target;
            for (vector<Cell>& row : Table)
            {
                for (Cell& cell : row)
                {
                    if (cell.GetParent() == Parent)
                    {
                        Target.push_back(&cell);
                    }
                }
            }
            
            for (Cell* cell : Target)
            {
                cell->Parent = cell;
                cell->Value.clear();
            }
            Table[r1][c1].Value = Value;
        }
    }
    return answer;
}