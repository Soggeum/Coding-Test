#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long TotalSum = 0;
    for (int n : queue1)
    {
        TotalSum += n;
    }
    for (int n : queue2)
    {
        TotalSum += n;
    }
    if (TotalSum & 1)
    {
        return -1;
    }
    TotalSum >>= 1;
    
    vector<int> q;
    q.reserve(queue1.size() * 3);
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
    
    int answer = 0, Start = 0, End = queue1.size();
    long long Sum = 0;
    for (int i = Start; i < End; i++)
    {
        Sum += queue1[i];
    }
    while (End <= q.size())
    {
        if (Sum == TotalSum)
        {
            return answer;
        }
        else if (Sum < TotalSum)
        {
            if (End == q.size())
            {
                return -1;
            }
            Sum += q[End++];
            answer++;
        }
        else
        {
            Sum -= q[Start++];
            answer++;
        }
    }
    
    return -1;
}