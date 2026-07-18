#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char n : number)
    {
        while (k && !answer.empty())
        {
            char top = answer.back();
            if (top < n)
            {
                answer.pop_back();
                k--;
            }
            else
            {
                break;
            }
        }
        answer.push_back(n);
    }
    
    while (k)
    {
        answer.pop_back();
        k--;
    }
    return answer;
}