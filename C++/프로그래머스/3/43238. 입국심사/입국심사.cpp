#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 0, end = 1000000000000000000, answer = 1000000000000000000;
    while (start <= end)
    {
        long long mid = (start + end) / 2, total = 0;
        for (int t : times)
        {
            total += mid / t;
        }
        if (total < n)
        {
            start = mid + 1;
        }
        else if (total >= n)
        {
            answer = min(answer, mid);
            end = mid - 1;
        }
    }

    return answer;
}

