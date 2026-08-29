#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long Get(int n, long long x)
{
    if (x == -1)
    {
        return 0;
    }
    if (n == 1)
    {
        if (x < 2)
        {
            return x + 1;
        }
        return x;
    }
    
    long long res= 0;
    int Ith = x / static_cast<long long>(pow(5, n - 1));
    if (Ith < 3)
    {
        res += Ith * static_cast<long long>(pow(4, n - 1));
    }
    else
    {
        res += (Ith - 1) * static_cast<long long>(pow(4, n - 1));
    }
    
    if (Ith == 2)
    {
        return res;
    }
    return res + Get(n - 1, x % static_cast<long long>(pow(5, n - 1)));
}

int solution(int n, long long l, long long r) {
    return Get(n, r - 1) - Get(n, l - 2);
}