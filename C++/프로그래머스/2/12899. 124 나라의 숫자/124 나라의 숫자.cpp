#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string res;
    while (n)
    {
        int r = n % 3;
        n /= 3;
        if (r == 0)
        {
            r = 4;
            n--;
        }
        res.push_back(r + '0');
    }
    
    return string(res.rbegin(), res.rend());
}