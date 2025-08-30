#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> X_table(10, 0);
    vector<int> Y_table(10, 0);
    
    for (char c: X) {
        X_table[c - '0']++;
    }
    for (char c: Y) {
        Y_table[c - '0']++;
    }
    
    for (int i = 9; i >= 0; i--) {
        answer.append( min(X_table[i], Y_table[i]), (i + '0'));        
    }
    
    if (answer.empty())
        return "-1";
    else if (answer[0] == '0')
        return "0";
    else 
        return answer;
}