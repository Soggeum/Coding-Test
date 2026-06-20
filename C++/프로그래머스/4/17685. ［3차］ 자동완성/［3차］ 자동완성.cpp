#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetDiffer(const string& a, const string& b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (i == b.size())
        {
            return i + 1;
        }
        
        if (a[i] != b[i])
        {
            return i + 1;
        }
    }
}

int solution(vector<string> words) {
    sort(words.begin(), words.end());
    
    int answer = 0;
    answer += GetDiffer(words[0], words[1]);
    
    int i = 1;
    for (; i < words.size() - 1; i++)
    {
        int Before = GetDiffer(words[i], words[i - 1]);
        int After = GetDiffer(words[i], words[i + 1]);
        
        answer += max(Before, After);
    }
    answer += GetDiffer(words[i], words[i - 1]);
        
    return answer;
}