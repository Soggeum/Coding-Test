#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long GetOne(int n, long long idx)
{
    if (idx < 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return (idx < 2) ? idx + 1 : idx;
    }
    
    long long Bundle = pow(5, n - 1);
    int BundleIdx = idx / Bundle;
    if (BundleIdx < 2)
    {
        long long res = 0;
        res += pow(4, n - 1) * BundleIdx;
        return res + GetOne(n - 1, idx % static_cast<long long>(pow(5, n - 1)));
    }
    else if (BundleIdx == 2)
    {
        return pow(4, n - 1) * 2;
    }
    else
    {
        long long res = 0;
        res += pow(4, n - 1) * (BundleIdx - 1);
        return res + GetOne(n - 1, idx % static_cast<long long>(pow(5, n - 1)));
    }
    
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    return GetOne(n, r - 1) - GetOne(n, l - 2);
}