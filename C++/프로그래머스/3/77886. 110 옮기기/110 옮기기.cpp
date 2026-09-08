#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {    
    vector<string> answer;
    for (const string& s1 : s)
    {
        int Cnt = 0;
        string temp = s1.substr(0, 2);
        for (int i = 2; i < s1.size(); i++)
        {
            temp.push_back(s1[i]);
            int n = temp.size();
            if (temp[n - 3] == '1' && temp[n - 2] == '1' && temp[n - 1] == '0')
            {
                Cnt++;
                temp.pop_back(); temp.pop_back(); temp.pop_back();
            }
        }
        
        int LastZero = -1;
        for (int i = temp.size() - 1; i >= 0;i--)
        {
            if (temp[i] == '0')
            {
                LastZero = i;
                break;
            }
        }
        
        string res = temp.substr(0, LastZero + 1);
        for (int i = 0; i < Cnt; i++)
        {
            res.append("110");
        }
        res.append(temp.substr(LastZero + 1));
        answer.push_back(res);
    }
    
    return answer;
}