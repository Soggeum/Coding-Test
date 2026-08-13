#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long Sum = 0;
    for (int q : queue1)
    {
        Sum += q;
    }
    for (int q : queue2)
    {
        Sum += q;
    }
    if (Sum & 1)
    {
        return -1;
    }
    Sum >>= 1;
    
    vector<int> q = queue1;
    for (int a : queue2)
    {
        q.push_back(a);
    }
    for (int a : queue1)
    {
        q.push_back(a);
    }
    int Start = 0, End = queue1.size();
    long long Curr = 0;
    for (int i  = Start; i < End; i++)
    {
        Curr += q[i];
    }
    int answer = 0;
    while (End <= q.size())
    {
        if (Curr == Sum)
        {
            return answer;
        }
        answer++;
        if (Curr < Sum)
        {
            if (End == q.size())
            {
                break;
            }
            Curr += q[End++];
        }
        else
        {
            Curr -= q[Start++];
        }
    }
    return -1;
}