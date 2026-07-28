#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> relation) {
    vector<int> answer;
    
    for (int i = 1; i < (1 << relation[0].size()); i++)
    {
        unordered_set<string> us;
        for (int r = 0; r < relation.size(); r++)
        {
            string t;
            for (int c = 0; c < relation[r].size(); c++)
            {
                if (i & (1 << c))
                {
                    t.append(relation[r][c]);
                    t.push_back(' ');
                }
            }
            if (us.find(t) == us.end())
            {
                us.insert(t);
            }
            else
            {
                break;
            }
        }
        
        if (us.size() == relation.size())
        {
            int idx = 0;
            for (; idx < answer.size(); idx++)
            {
                if ((answer[idx] & i) == answer[idx])
                {
                    break;
                }
            }
            if (idx == answer.size())
            {
                answer.push_back(i);
            }
        }
    }
    
    return answer.size();
}