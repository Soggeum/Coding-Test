#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int Row = relation.size(), Column = relation[0].size();
    
    vector<int> Keys;
    for (int i = 1; i < (1 << Column); i++)
    {
        set<string> s;
        for (int row = 0; row < Row; row++)
        {
            string Temp;
            for (int col = 0; col < Column; col++)
            {
                if (i & (1 << col))
                {
                    Temp.append(relation[row][col]);
                    Temp.push_back(' ');
                }
            }
            s.insert(Temp);
        }
        
        if (s.size() == Row)
        {
            int x = 0;
            for (; x < Keys.size(); x++)
            {
                if ((Keys[x] & i) == Keys[x])
                {
                    break;
                }
            }
            if (x == Keys.size())
            {
                Keys.push_back(i);
            }
        }
    }
    
    return Keys.size();
}