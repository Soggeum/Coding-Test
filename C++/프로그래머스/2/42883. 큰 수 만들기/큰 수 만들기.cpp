#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char c : number)
    {
        while (k && !answer.empty())
        {
            char back = answer.back();
            if (back < c)
            {
                k--;
                answer.pop_back();
            }
            else
            {
                break;
            }
        }
        answer.push_back(c);
    }
    
    while (k)
    {
        answer.pop_back();
        k--;
    }
    
    if (answer[0] == '0')
    {
        return "0";
    }
    return answer;
}