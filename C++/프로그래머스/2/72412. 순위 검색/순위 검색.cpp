#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

void Push(unordered_map<string, vector<int>>& um, const string& s)
{
    vector<string> Type(4);
    int X;
    stringstream ss(s);
    
    ss >> Type[0] >> Type[1] >> Type[2] >> Type[3] >> X;
    for (int i = 0; i < (1 << 4); i++)
    {
        string Temp;
        for (int j = 0; j < 4; j++)
        {
            if (i & (1 << j))
            {
                Temp.append(Type[j]);
            }
            else
            {
                Temp.push_back('-');
            }
        }
        um[Temp].push_back(X);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, vector<int>> um;
    for (const string& i : info)
    {
        Push(um, i);
    }
    
    for (auto& it : um)
    {
        sort(it.second.begin(), it.second.end());
    }
    
    vector<int> answer;
    for (const string& q : query)
    {
        stringstream ss(q);
        string a, b, c, d, e, f, g;
        int X;
        ss >> a >> b >> c >> d >>e >>f>> g>> X;
        string Temp;
        Temp.append(a).append(c).append(e).append(g);
        auto it = lower_bound(um[Temp].begin(), um[Temp].end(), X);
        answer.push_back(um[Temp].end() - it);
    }
    
    return answer;
}