#include <string>
#include <vector>

using namespace std;

long long fibo(int n, vector<int>& table) {
    
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (table[n] != -1)
        return table[n];
    
    table[n] = fibo(n - 1, table) % 1234567 + fibo(n - 2, table) % 1234567;
    return table[n];
}

int solution(int n) {
    vector<int> table(n + 1, -1);

    return fibo(n, table) % 1234567;
}