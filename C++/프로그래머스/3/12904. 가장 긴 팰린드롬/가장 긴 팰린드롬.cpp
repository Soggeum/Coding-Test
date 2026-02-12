#include <string>

using namespace std;

int solution(string s)
{
    int answer = 1;
    
    int temp;
    for (int i = 0; i < s.size(); i++)
    {
        temp = 1;
        for (int j = 1; i - j >= 0 && i + j < s.size(); j++)
        {
            if (s[i - j] != s[i + j])
            {
                break;
            }
            temp += 2;
        }
        answer = (answer > temp) ? answer : temp;
        
        if (i + 1 < s.size() && s[i] == s[i + 1])
        {
            temp = 2;
            for (int j = 1; i - j >= 0 && i + 1 + j < s.size(); j++)
            {
                if (s[i - j] != s[i + j + 1])
                {
                    break;
                }
                temp += 2;
            }
            answer = (answer > temp) ? answer : temp;
        }
    }

    return answer;
}