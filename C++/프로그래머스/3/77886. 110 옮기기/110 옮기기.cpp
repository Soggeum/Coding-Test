#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (const string& str : s)
    {
        string x;
        int cnt = 0;
        for (char c : str)
        {
            x.push_back(c);
            while (x.size() >= 3 && x.substr(x.size() - 3) == "110")
            {
                x.pop_back(); x.pop_back(); x.pop_back();
                cnt++;
            }
        }
        
        int LastZero = 0;
        for (int i = x.size() - 1; i >= 0; i--)
        {
            if (x[i] == '0')
            {
                LastZero = i + 1;
                break;
            }
        }
        
        string res = x.substr(0, LastZero);
        for (int i = 0; i < cnt; i++)
        {
            res.append("110");
        }
        res.append(x.substr(LastZero));
        answer.push_back(res);
    }
    return answer;
}