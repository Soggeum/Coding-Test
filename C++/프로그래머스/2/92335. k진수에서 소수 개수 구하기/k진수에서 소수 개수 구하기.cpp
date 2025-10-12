#include <string>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string change(int n, int k)
{
    if (k == 10) return to_string(n);
    string result;
    while (n >= k) {
        result.push_back(n % k + '0');
        n /= k;
    }
    result.push_back(n + '0');
    
    return string(result.rbegin(), result.rend());
}

bool IsPrime(string str)
{
    if (str.empty() || str == string("1"))
        return false;
    
    long long n = stol(str);
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string k_num = change(n, k);
    
    string temp;
    for (const char& c : k_num)
    {
        if (c != '0')
        {
            temp.push_back(c);
        }
        else
        {
            if (IsPrime(temp))
                answer++;
            temp.clear();
        }
    }
    if (IsPrime(temp))
        answer++;
    
    return answer;
}