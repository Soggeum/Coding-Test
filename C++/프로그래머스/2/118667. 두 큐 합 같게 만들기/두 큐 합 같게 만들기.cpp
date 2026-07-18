#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> q;
    long long Sum = 0;
    for (int n : queue1)
    {
        q.push_back(n);
        Sum += n;
        
    }
    for (int n : queue2)
    {
        q.push_back(n);
        Sum += n;
    }
    for (int n : queue1)
    {
        q.push_back(n);
    }
    
    if (Sum & 1)
    {
        return -1;
    }
    Sum = Sum >> 1;
    
    int answer = 0, Start = 0, End = queue1.size();
    long long CurrSum = 0;
    for (int i = Start; i < End; i++)
    {
        CurrSum += q[i];
    }
    while (Start <= End && End <= q.size())
    {
        if (CurrSum > Sum)
        {
            CurrSum -= q[Start++];
            answer++;
        }
        else if (CurrSum < Sum)
        {
            if (End == q.size())
            {
                return -1;
            }
            CurrSum += q[End++];
            answer++;
        }
        else
        {
            return answer;
        }
    }
    return -1;
}