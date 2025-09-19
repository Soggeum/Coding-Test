#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

bool isOkay(const string& s) {
    stack<char> st;
    st.push(-1);
    
    for (const char& c : s) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else if (c == ')')  {
            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if (c == '}')  {
            if (st.top() == '{')
                st.pop();
            else
                return false;
        }
        else if (c == ']')  {
            if (st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    
    if (st.top() == -1)
        return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        if (isOkay(s))
            answer++;
        s.push_back(s[0]);
        s.erase(s.begin(), s.begin() + 1);
    }
    
    return answer;
}