#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> Table;
    for (int i = 0; i < name.size(); i++)
    {
        Table[name[i]] = yearning[i];
    }
    vector<int> answer;
    for (const vector<string>& Ph : photo)
    {
        int sum = 0;
        for (const string& elem : Ph)
        {
            sum += Table[elem];
        }
        answer.push_back(sum);
    }
    return answer;
}