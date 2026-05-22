#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev_row(n);
    vector<int> next_row(n);
    
    for (int i = 0; i < n; i++) {
        prev_row[i] = i - 1;
        next_row[i] = i + 1;
    }
    prev_row[0] = -1;
    next_row[n - 1] = -1;

    stack<int> deleted;
    vector<bool> is_deleted(n, false);

    for (const string& s : cmd) {
        if (s[0] == 'U') {
            int x = stoi(s.substr(2));
            while (x--) {
                k = prev_row[k];
            }
        } 
        else if (s[0] == 'D') {
            int x = stoi(s.substr(2));
            while (x--) {
                k = next_row[k];
            }
        } 
        else if (s[0] == 'C') {
            deleted.push(k);
            is_deleted[k] = true;

            int prev = prev_row[k];
            int next = next_row[k];

            if (prev != -1) next_row[prev] = next;
            if (next != -1) prev_row[next] = prev;

            if (next != -1) {
                k = next;
            } else {
                k = prev;
            }
        } 
        else if (s[0] == 'Z') {
            int restore = deleted.top();
            deleted.pop();
            is_deleted[restore] = false;

            int prev = prev_row[restore];
            int next = next_row[restore];

            if (prev != -1) next_row[prev] = restore;
            if (next != -1) prev_row[next] = restore;
        }
    }

    string answer = "";
    answer.reserve(n);
    for (int i = 0; i < n; i++) {
        if (is_deleted[i]) answer += 'X';
        else answer += 'O';
    }
    
    return answer;
}