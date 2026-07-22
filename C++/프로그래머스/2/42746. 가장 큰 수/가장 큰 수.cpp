#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (const int& a, const int& b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp);
    string answer = "";
    for (int n : numbers)
    {
        answer.append(to_string(n));
    }
    if (answer[0] == '0')
    {
        return "0";
    }
    return answer;
}