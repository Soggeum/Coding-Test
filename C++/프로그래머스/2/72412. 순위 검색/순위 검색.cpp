#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

void DFS(const vector<vector<string>>& Comb, vector<string>& Cur, int i, map<vector<string>, vector<int>>& m)
{
    if (i == 4)
    {
        m[Cur] = {};
        return;
    }
    
    for (int j = 0; j < Comb[i].size(); j++)
    {
        Cur.push_back(Comb[i][j]);
        DFS(Comb, Cur, i + 1, m);
        Cur.pop_back();
    }
}

void Push(const vector<vector<string>>& Comb, vector<string>& Cur, int i, map<vector<string>, vector<int>>& m, int X)
{
    if (i == 4)
    {
        m[Cur].push_back(X);
        return;
    }
    
    for (int j = 0; j < Comb[i].size(); j++)
    {
        Cur.push_back(Comb[i][j]);
        Push(Comb, Cur, i + 1, m, X);
        Cur.pop_back();
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<vector<string>> Comb = 
    {
        {"cpp", "java", "python", "-"},
        {"backend", "frontend", "-"},
        {"junior", "senior", "-"},
        {"chicken", "pizza", "-"}
    };
    map<vector<string>, vector<int>> m;
    vector<string> Cur;
    DFS(Comb, Cur, 0, m);
    
    vector<vector<string>> Base = 
        {
        {"-"},
        {"-"},
        {"-"},
        {"-"}
    };
    for (const string& i : info)
    {
        vector<string> is(4);
        int X;
        stringstream ss(i);
        ss >> is[0] >> is[1] >> is[2] >> is[3] >> X;
        for (int i = 0; i < 4; i++)
        {
            Base[i].push_back(is[i]);
        }
        Push(Base, Cur, 0, m, X);
        for (int i = 0; i < 4; i++)
        {
            Base[i].pop_back();
        }
    }
    
    for (auto& it : m)
    {
        sort(it.second.begin(), it.second.end());
    }

    vector<int> answer;
    for (const string& q : query)
    {
        stringstream ss(q);
        vector<string> vs(4);
        string a1, a2, a3;
        int X;
        ss >> vs[0] >> a1 >> vs[1] >> a2 >> vs[2] >> a3 >> vs[3] >> X;
        answer.push_back(m[vs].end() - lower_bound(m[vs].begin(), m[vs].end(), X));
    }
    
    return answer;
}