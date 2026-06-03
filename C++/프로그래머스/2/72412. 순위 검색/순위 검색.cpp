#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void DFS(const string& Lan, const string& Job, const string& Exp, const string& Food, string& Key, int idx, vector<string>& result)
{
    if (idx == 4)
    {
        result.push_back(Key);
        return;
    }
    
    string Temp = Key;
    switch(idx) 
    {
        case 0 :
            Temp.append(Lan);
            Temp.append(" and ");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            
            Temp = Key;
            Temp.append("- and ");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            break;
            
        case 1:
            Temp.append(Job);
            Temp.append(" and ");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            
            Temp = Key;
            Temp.append("- and ");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            break;
            
        case 2:
            Temp.append(Exp);
            Temp.append(" and ");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            
            Temp = Key;
            Temp.append("- and ");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            break;
            
        default :
            Temp.append(Food);
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
            
            Temp = Key;
            Temp.append("-");
            DFS(Lan, Job, Exp, Food, Temp, idx + 1, result);
    }
}

vector<string> MakeComb(const string& Lan, const string& Job, const string& Exp, const string& Food)
{    
    vector<string> result;
    result.reserve(16);
    
    string Key;
    DFS(Lan, Job, Exp, Food, Key, 0, result);    
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, vector<int>> um;
    for (const string& Elem : info)
    {
        stringstream ss(Elem);
        string Lan, Job, Exp, Food;
        int Score;
        ss >> Lan >> Job >> Exp >> Food >> Score;
        
        vector<string> Keys = MakeComb(Lan, Job , Exp, Food);
        for (const string& Key : Keys)
        {
            um[Key].push_back(Score);
        }
    }
    
    for (auto& it : um)
    {
        sort(it.second.begin(), it.second.end());
    }
    
    vector<int> answer;
    for (string q : query)
    {
        int idx = q.size() - 1;
        while (isdigit(q[idx]))
        {
            idx--;
        }
        int Score = stoi(q.substr(idx + 1));
        for (int i = q.size() - 1; i >= idx; i--)
        {
            q.pop_back();
        }
        
        auto it = lower_bound(um[q].begin(), um[q].end(), Score);
        answer.push_back(um[q].end() - it);
    }
    return answer;
}