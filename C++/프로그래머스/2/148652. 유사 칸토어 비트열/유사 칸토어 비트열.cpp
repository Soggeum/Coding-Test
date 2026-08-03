#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long GetOne(int n, long long i)
{
    if (i < 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return i < 2 ? i + 1 : i;
    }
    
    long long res = 0;
    int Idx = i / static_cast<long long>(pow(5, n - 1));
    res += (Idx < 3 ? pow(4, n - 1) * Idx : pow(4, n - 1) * (Idx - 1)); 
    
    if (Idx == 2)
    {
        return res;
    }
    return res + GetOne(n - 1, i % static_cast<long long>(pow(5, n - 1)));
}

int solution(int n, long long l, long long r) {
    return GetOne(n, r - 1) - GetOne(n, l - 2);
}