#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> S;
    vector<int> SElem;
    string temp;
    for (char& c : s)
    {
        if (isdigit(c))
        {
            temp.push_back(c);
        }
        else if (c == ',')
        {
            if (!temp.empty())
            {
                SElem.push_back(stoi(temp));
                temp.clear();
            }
        }
        else if (c == '}')
        {
            if (!temp.empty())
            {
                SElem.push_back(stoi(temp));
                S.push_back(SElem);
                temp.clear();
                SElem.clear();
            }
        }
    }
    
    sort(S.begin(), S.end(), comp);
    
    unordered_set<int> us;
    vector<int> answer;
    
    for (const vector<int>& SElem : S)
    {
        for (const int& elem : SElem)
        {
            if (us.find(elem) == us.end())
            {
                answer.push_back(elem);
                us.insert(elem);
                break;
            }
        }
    }
    
    return answer;
}