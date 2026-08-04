#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char c : number)
    {
        while (k &&!answer.empty() && answer.back() < c)
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    
    while (k)
    {
        answer.pop_back();
        k--;
    }
    return answer;
}