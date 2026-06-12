#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int l, m, r, n = cookie.size(), answer = 0, First, Second;
    for (m = 0; m < cookie.size() - 1; m++)
    {
        l = m;
        r = m + 1;
        First = cookie[l];
        Second = cookie[r];
        while (0 <= l && r < n)
        {            
            if (First == Second)
            {
                answer = max(answer, First);
                if (l == 0 || r == n -1)
                {
                    break;
                }
                First += cookie[--l];
                Second += cookie[++r];
            }
            else if (First < Second)
            {
                if (l == 0)
                {
                    break;
                }
                First += cookie[--l];
            }
            else
            {
                if (r == n - 1)
                {
                    break;
                }
                Second += cookie[++r];
            }
        }
        
    }
    
    return answer;
}