#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct comp
{
    bool operator()(const int& a, const int& b) const
    {
        string A = to_string(a), B = to_string(b);
        return A + B > B + A;
    }  
};

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp());
    if (numbers[0] == 0)
    {
        return "0";
    }
    
    string answer = "";
    for (int n : numbers)
    {
        answer.append(to_string(n));
    }
    
    return answer;
}