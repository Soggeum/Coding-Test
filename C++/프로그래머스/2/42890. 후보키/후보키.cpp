#include <string>
#include <vector>
#include <unordered_set>

// 유일성, 최소성
// 비트마스킹, 로우 돌면서 set에 넣기
// 크기 정확하면 최소성 검사
// 최소성은 이전 후보키들 & 해서 같으면 불만족

using namespace std;

int solution(vector<vector<string>> relation) {
    int N = relation.size(), M = relation[0].size();
    vector<int> Key;
    for (int i = 1; i < (1 << M); i++)
    {
        unordered_set<string> us;
        for (int row = 0; row < N; row++)
        {
            string s;
            for (int j = 0; j < M; j++)
            {
                if (i & (1 << j))
                {
                    s.append(relation[row][j]);
                    s.push_back(' ');
                }
            }    
            us.insert(s);
        }
        
        if (us.size() == N)
        {
            bool bFlag = true;
            for (int k : Key)
            {
                if ((k & i) == k)
                {
                    bFlag = false;
                    break;
                }
            }
            if (bFlag)
            {
                Key.push_back(i);
            }
        }
    }
    
    return Key.size();
}