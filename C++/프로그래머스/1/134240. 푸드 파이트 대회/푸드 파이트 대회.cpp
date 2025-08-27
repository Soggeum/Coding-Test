#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 1; i < food.size(); i++) {
        answer.append(food[i] / 2, i + '0');
    }
    
    string reverse(answer.rbegin(), answer.rend());
    answer.push_back('0');
    answer.append(reverse);
    return answer;
}