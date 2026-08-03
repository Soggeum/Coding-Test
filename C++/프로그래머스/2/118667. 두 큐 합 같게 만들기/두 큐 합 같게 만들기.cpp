#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long Total = 0;
    for (int q : queue1)
    {
        Total += q;
    }
    for (int q : queue2)
    {
        Total += q;
    }
    if (Total & 1)
    {
        return -1;
    }
    Total >>= 1;
    
    int Left = 0, Right = queue1.size();
    long long sum = 0;
    for (int i = 0; i < Right; i++)
    {
        sum += queue1[i];
    }
    vector<int> q;
    for (int n : queue1)
    {
        q.push_back(n);
    }
    for (int n : queue2)
    {
        q.push_back(n);
    }
    for (int n : queue1)
    {
        q.push_back(n);
    }
    
    int answer = 0;
    while (Right <= q.size())
    {
        if (sum < Total)
        {
            if (Right == q.size())
            {
                return -1;
            }
            sum += q[Right++];
        }
        else if (sum == Total)
        {
            return answer;
        }
        else
        {
            sum -= q[Left++];
        }
        answer++;
    }
    
    return answer;
}