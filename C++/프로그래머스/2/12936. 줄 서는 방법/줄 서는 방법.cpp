#include <string>
#include <vector>
#include <set>

using namespace std;

long long Factorial(int n)
{
    static vector<long long> Fact(21, -1);
    if (Fact[n] != -1)
    {
        return Fact[n];
    }
    
    Fact[0] = 1;
    Fact[1] = 1;
    for (int i = 2; i < 21; i++)
    {
        Fact[i] = Fact[i - 1] * i;
    }
    return Fact[n];
}

vector<int> DFS(set<int> Targets, long long k)
{
    if (Targets.size() == 1)
    {
        return {*Targets.begin()};
    }
    
    long long cnt = 0;
    int n = Targets.size();
    vector<int> result;
    for (int Target : Targets)
    {
        cnt += Factorial(n - 1);
        if (cnt >= k)
        {
            result.push_back(Target);
            Targets.erase(Target);
            vector<int> Back = DFS(Targets, k - (cnt - Factorial(n - 1)));
            for (int b : Back)
            {
                result.push_back(b);
            }
            return result;
        }
    }
}

vector<int> solution(int n, long long k) {    
    set<int> Targets;
    for (int i = 1; i <= n; i++)
    {
        Targets.insert(i);
    }
    
    return DFS(Targets, k);
}