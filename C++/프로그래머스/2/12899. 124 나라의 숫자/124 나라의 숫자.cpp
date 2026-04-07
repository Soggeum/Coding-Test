#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> Left = {4, 1, 2};
    while(n)
    {
        int L = n % 3;
        n /= 3;
        if (L == 0)
        {
            n--;
        }
        answer.push_back('0' + Left[L]);
    }
    
    return string(answer.rbegin(), answer.rend());
}