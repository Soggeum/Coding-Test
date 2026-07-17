#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<unordered_set<int>> Table(501);
    unordered_set<int> Temp;
    string TempElem;
    for (int i = 2; i < s.size(); i++)
    {
        if (s[i] == '}')
        {
            Temp.insert(stoi((TempElem)));
            Table[Temp.size()] = Temp;
            TempElem.clear();
            Temp.clear();
            i += 2;
        }
        else if (s[i] == ',')
        {
            Temp.insert(stoi(TempElem));
            TempElem.clear();
        }
        else
        {
            TempElem.push_back(s[i]);
        }
    }
    
    vector<bool> Appear(100001);
    vector<int> answer;
    for (int i = 1; i < Table.size(); i++)
    {
        if (Table[i].empty())
        {
            break;
        }
        for (int value : Table[i])
        {
            if (!Appear[value])
            {
                answer.push_back(value);
                Appear[value] = true;
                break;
            }
        }
    }
    
    return answer;
}