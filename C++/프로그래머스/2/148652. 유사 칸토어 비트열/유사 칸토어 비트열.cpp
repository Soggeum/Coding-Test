#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> PowFive(21, 5);
vector<long long> PowFour(21, 4);

long long OneCount(int n, long long i)
{
    if (n == 1)
    {
        return i < 3 ? i : i - 1;
    }
    //int r = (i - 1) / static_cast<long long>(pow(5, n - 1));
    int r = (i - 1) / PowFive[n - 1];
    
    long long res = 0;
    if (r < 2)
    {
        //res += static_cast<long long>(pow(4, n - 1)) * r;
        res += PowFour[n - 1] * r;
    }
    else if (r == 2)
    {
        return PowFour[n - 1] * 2;
    }
    else
    {
        //res += static_cast<long long>(pow(4, n - 1)) * (r - 1);
        res += PowFour[n - 1] * (r - 1);
    }
    
    //i -= static_cast<long long>(pow(5, n - 1)) * r;
    i -= PowFive[n - 1] * r;
    return res + OneCount(n - 1, i);
}

int solution(int n, long long l, long long r) {
    for (int i = 2; i < 21; i++)
    {
        PowFive[i] = PowFive[i - 1] * 5;
        PowFour[i] = PowFour[i - 1] * 4;
    }
    return OneCount(n, r) - OneCount(n, l - 1);
}