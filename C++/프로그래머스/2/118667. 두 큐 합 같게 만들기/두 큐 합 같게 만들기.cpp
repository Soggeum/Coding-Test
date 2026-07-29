#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long Sum = 0;
    for (int n : queue1)
    {
        Sum += n;
    }
    for (int n : queue2)
    {
        Sum += n;
    }
    if (Sum & 1)
    {
        return -1;
    }
    
    Sum = Sum >> 1;
    int answer = 0;
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
    
    int Start = 0, End = queue1.size();
    long long Curr = 0;
    for (int i = Start; i < End; i++)
    {
        Curr += q[i];
    }
    while(End <= q.size())
    {
        if (Curr == Sum)
        {
            return answer;
        }
        if (Curr < Sum)
        {
            if (End == q.size())
            {
                return -1;
            }
            Curr += q[End++];
            answer++;
        }
        else
        {
            Curr -= q[Start++];
            answer++;
        }
    }
    
    return -1;
}