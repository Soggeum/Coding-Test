#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> y = {k};
    while (k != 1) {
        if (k & 1)
            k = k * 3 + 1;
        else
            k = k / 2;
        y.push_back(k);
    }
    int n = y.size() - 1;
    
    vector<double> SizeFromZero(y.size(), 0.0);
    for (int i = 1; i < y.size(); i++) {
        SizeFromZero[i] = SizeFromZero[i - 1] + (y[i-1] + y[i]) * 0.5;
    }
    
    vector<double> answer;
    int a, b;
    for (vector<int>& range : ranges) {        
        if (range[0] == 0 && range[1] == 0) {
            answer.push_back(SizeFromZero[n]);
            continue;
        }
        
        a = range[0]; b = range[1];
        if (b <= 0)
            b = n + b;
        
        if (a > b) {
                answer.push_back(-1);
                continue;
            }
        
        answer.push_back(SizeFromZero[b] - SizeFromZero[a]);
    }
    return answer;
}