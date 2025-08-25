#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len = p.size();
    long long ll_p = stoll(p);
    for (int i = 0; i < t.size() - len + 1; i++) {
        if (stoll(t.substr(i, len)) <= ll_p)
            answer++;        
    }
    
    return answer;
}