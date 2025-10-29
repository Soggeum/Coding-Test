#include <string>
#include <stack>
using namespace std;

string solution(string number, int k) {
    stack<char> st;
    int removeCount = 0;

    for (char num : number) {
        while (!st.empty() && st.top() < num && removeCount < k) {
            st.pop();
            removeCount++;
        }
        st.push(num);
    }

    // 아직 제거해야 할 개수가 남아있을 경우 뒤에서 제거
    while (removeCount < k) {
        st.pop();
        removeCount++;
    }

    // 스택에 남은 숫자를 뒤에서부터 결과 문자열에 추가
    string answer = "";
    while (!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }

    return answer;
}
