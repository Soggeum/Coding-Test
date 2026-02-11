#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 1, end = static_cast<long long>(100000000) * 1000000000, mid;
    
    long long Possible;
    while (start <= end)
    {
        mid = (start + end) / 2;
        Possible = 0;
        for (int time : times)
        {
            Possible += mid / time;
        }
        
        if (Possible < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return start;
}