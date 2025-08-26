#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
	vector<int> temp;
    for (vector<int> it : commands) {
        temp = vector<int>(array.begin() + (it[0] - 1), array.begin() + it[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[it[2] - 1]);
    }
    return answer;
}