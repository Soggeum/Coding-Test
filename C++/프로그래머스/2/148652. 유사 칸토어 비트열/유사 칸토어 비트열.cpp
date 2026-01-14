#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> FivePow(21, 1);
vector<long long> FourPow(21, 1);

long long CountFromStart(long long n, long long End)
{
    if (n == 1) 
    {
        if (End < 3) return End;
        else return End - 1;
    }
    
    long long result = 0;
    long long Idx = (End - 1) / FivePow[n - 1];   
    if (Idx <= 2)
    {
        result += FourPow[n - 1] * Idx;
    }
    else
    {
        result += FourPow[n - 1] * (Idx - 1);
    }
    
    if (Idx != 2)
    {
        result += CountFromStart(n - 1, (End - 1) % FivePow[n - 1] + 1);
    }
        
    return result;
}

int solution(int n, long long l, long long r) { 
    for (int i = 1; i <= n; i++)
    {
        FivePow[i] = FivePow[i - 1] * 5;
        FourPow[i] = FourPow[i - 1] * 4;
    }
    
    int answer = CountFromStart(n, r) - CountFromStart(n, l - 1);
    return answer;
}
    