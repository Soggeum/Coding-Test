#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int&a, const int& b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp);
    
    string answer = "";
    int zero_cnt = 0;
    for (int number : numbers) {
        answer.append(to_string(number));
        if (number == 0)
            zero_cnt++;
    }
    
    if (zero_cnt == answer.size())
        return "0";
    
    return answer;
}