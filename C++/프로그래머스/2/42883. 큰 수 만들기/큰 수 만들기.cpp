#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = 0; i < number.size(); i++)
    {
        while (k && !answer.empty())
        {
            if (answer.back() < number[i])
            {
                answer.pop_back();
                k--;
            }
            else
            {
                break;
            }
        }
        answer.push_back(number[i]);
    }
    
    while (k)
    {
        answer.pop_back();
        k--;
    }
    
    return answer;
}