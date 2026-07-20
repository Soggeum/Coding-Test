#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n)
    {
        int r = n % 3;
        n /= 3;
        if (r == 0)
        {
            r = 4;
            n--;
        }
        answer.push_back(r + '0');
    }
    
    return string(answer.rbegin(), answer.rend());
}