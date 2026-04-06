#include <string>
#include <vector>

using namespace std;

bool CanDo(const string& skill_tree, const vector<int>& Table)
{
    int order = 0;
    for (char c : skill_tree)
    {
        int value = Table[c - 'A'];
        if (value == -1)
        {
            continue;
        }
        if (value == order)
        {
            order++;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    vector<int> Table(26, -1);
    for (int order = 0; order < skill.size(); order++)
    {
        Table[skill[order] - 'A'] = order;
    }
    
    int answer = 0;
    for (const string& skill_tree : skill_trees)
    {
        if (CanDo(skill_tree, Table))
        {
            answer++;
        }
    }
    
    return answer;
}