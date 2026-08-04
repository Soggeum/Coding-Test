#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

void Put(unordered_map<string, vector<int>>& Table, const vector<string>& A, int X)
{
    for (int i = 0; i < (1 << 4); i++)
    {
        string key;
        for (int j = 0; j < 4; j++)
        {
            if (i & (1 << j))
            {
                key.append(A[j]);
            }
            else
            {
                key.push_back('-');
            }
            if (j < 3)
            {
                key.append(" and ");
            }
        }
        
        Table[key].push_back(X);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, vector<int>> Table;
    for (const string& i : info)
    {
        vector<string> A(4);
        int X;
        stringstream ss(i);
        ss >> A[0] >> A[1] >> A[2] >> A[3] >> X;
        
        Put(Table, A, X);
    }
    
    for (auto& it : Table)
    {
        sort(it.second.begin(), it.second.end());
    }
    
    vector<int> answer;
    for (const string& q : query)
    {
        string key;
        int X;
        for (int i = 0; i < q.size(); i++)
        {
            if (isdigit(q[i]))
            {
                key = q.substr(0, i - 1);
                X = stoi(q.substr(i));
                break;
            }
        }
        
        auto it = lower_bound(Table[key].begin(), Table[key].end(), X);
        answer.push_back(Table[key].end() - it);
    }
    return answer;
}