#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<int> citations) { 
    sort(citations.begin(), citations.end());
    
    int n = citations.size();
    int pre = -1, cnt;
    for (int i = 0; i < n; i++) {
        if (citations[i] != pre) {
            cnt = n - i;
            pre = i;
        }
        if (citations[i] > cnt) {
            return max(pre, cnt);
        }
    }
    
    return pre;
}