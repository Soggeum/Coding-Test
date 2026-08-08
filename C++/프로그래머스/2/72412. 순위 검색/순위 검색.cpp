#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

void Push(unordered_map<string, vector<int>>& Table, const vector<string>& vs, int X)
{
    for (int i = 0; i < (1 << 4); i++)
    {
        string key;
        for (int j = 0;j < 4; j++)
        {
            if (i & (1 << j))
            {
                key.append(vs[j]);
            }
            else
            {
                key.push_back('-');
            }
            key.push_back(' ');
        }
        Table[key].push_back(X);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, vector<int>> Table;
    for (const string& i : info){
        vector<string> vs(4);
        int X;
        stringstream ss(i);
        ss >> vs[0] >> vs[1] >> vs[2] >> vs[3] >> X;
        Push(Table, vs, X);
    }
    
    for (auto& it : Table)
    {
        sort(it.second.begin(), it.second.end());
    }
    
    vector<int> answer;
    for (const string& q : query)
    {
        string a, b, c, d, e, f, g;
        int X;
        stringstream ss(q);
        ss >> a >> b >> c>> d>>e>>f>>g>>X;
        string key = a;
        key.push_back(' ');
        key.append(c);
        key.push_back(' ');
        key.append(e);
        key.push_back(' ');
        key.append(g);
        key.push_back(' ');
        
        const auto& it = Table.find(key);
        if (it != Table.end())
        answer.push_back(it->second.end() - lower_bound(it->second.begin(), it->second.end(), X));
        else
            answer.push_back(0);
    }
    
    return answer;
}