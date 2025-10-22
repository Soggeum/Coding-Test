#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int& int_a, int& int_b) {
    string a = to_string(int_a);
    string b = to_string(int_b);
    
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp);
    
    string answer = "";
    for (int number : numbers)
        answer.append(to_string(number));
    
    for (char c : answer) {
        if (c != '0')
            return answer;
    }
    
    return "0";
}