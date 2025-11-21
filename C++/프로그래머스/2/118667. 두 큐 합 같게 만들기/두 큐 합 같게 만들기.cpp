#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long Sum = 0;
    for (int i = 0; i < queue1.size(); i++) {
        Sum += queue1[i] + queue2[i];
    }
    if (Sum & 1)
        return -1;
    Sum /= 2;
    
    int l = 0, r = queue1.size() - 1;
    vector<int> q = queue1;
    for (int num : queue2) {
        q.push_back(num);
    }
    long long s = 0;
    for (int num : queue1) {
        q.push_back(num);
        s += num;
    }
    
    int answer = 0;
    while (r <= q.size() - 1) {
        if (s == Sum)
            return answer;
        if (s < Sum) {
            answer++;
            r++;
            if (r == q.size())
                return -1;
            s += q[r];
        }
        else {
            answer++;
            s -= q[l];
            l++;
            if (l == q.size())
                return -1;
        }
    }
    return -1;
}