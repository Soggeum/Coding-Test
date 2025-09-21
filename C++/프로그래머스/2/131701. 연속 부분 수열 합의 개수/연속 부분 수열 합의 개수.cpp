#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    elements.resize(elements.size() * 2 - 1);
    for(int i = 0; i < n - 1; i++) {
        elements[n + i] = elements[i];
    }
    
    
    unordered_set<int> answer; 
    vector<int> each_sum(elements.size());
    for (int i = 0; i < n; i++) {
        for (int start = 0; start < n; start++) {
            each_sum[start] += elements[start + i];
            answer.insert(each_sum[start]);
        }
    }
    
    return answer.size();
}