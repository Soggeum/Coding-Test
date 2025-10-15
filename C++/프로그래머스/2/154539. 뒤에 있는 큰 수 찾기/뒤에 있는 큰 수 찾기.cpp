#include <string>
#include <vector>
#include <stack>

using namespace std;

int ProcessStack(int num, stack<int>& SortedBackNum) {
    int top;
    while (!SortedBackNum.empty()) {
        top = SortedBackNum.top();
        if (num >= top) {
            SortedBackNum.pop();
        }
        else {
            SortedBackNum.push(num);
            return top;
        }
    }

    if (SortedBackNum.empty()) {
        SortedBackNum.push(num);
        return -1;
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), 0);
    stack<int> SortedBackNum;
    answer[numbers.size() - 1] = -1;
    SortedBackNum.push(numbers[numbers.size() - 1]);

    for (int i = numbers.size() - 2; i >= 0; i--)
    {
        if (numbers[i] < numbers[i + 1]) {
            answer[i] = numbers[i + 1];
            SortedBackNum.push(numbers[i]);
        }
        else {
            answer[i] = ProcessStack(numbers[i], SortedBackNum);
        }
    }

    return answer;
}