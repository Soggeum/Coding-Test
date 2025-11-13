#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> q = queue1;
    long long Q1Sum = 0, Sum = 0;
    for (int num : queue1) {
        Q1Sum += num;
    }
    Sum = Q1Sum;
    for(int num : queue2) {
        q.push_back(num);
        Sum += num;
    }
    if (Sum & 1)
        return -1;
    Sum /= 2;
    
    for (int num : queue1)
        q.push_back(num);
    
    int low = 0, high = queue1.size() - 1;
    int Cnt = 0;
    while (high < q.size()) {
        if (Q1Sum == Sum)
            return Cnt;
        if (Q1Sum < Sum) {
            high++;
            Cnt++;
            if (high == q.size())
                return -1;
            Q1Sum += q[high];
        }
        if (Q1Sum > Sum) {
            Q1Sum -= q[low++];
            Cnt++;
        }
    }
    
    return -1;
    
}