#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int row = relation.size(), col = relation[0].size();
    vector<int> answer;
    for (int bit = 1; bit < (1 << col); bit++)
    {
        unordered_set<string> us;
        for (int i = 0; i < row; i++)
        {
            string s;
            for (int j = 0; j < col; j++)
            {
                if (bit & (1 << (col - 1 - j)))
                {
                    s.append(relation[i][j]);
                    s.push_back(' ');
                }
            }
            us.insert(s);
        }
        
        if (us.size() == row)
        {
            int i = 0;
            for (; i < answer.size(); i++)
            {
                if ((answer[i] & bit) == answer[i])
                {
                    break;
                }
            }
            if (i == answer.size())
            {
                answer.push_back(bit);
            }
        }
    }
    
    return answer.size();
}