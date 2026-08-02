#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (const string& cs : s)
    {
        string x;
        int count = 0;
        for (char c : cs)
        {
            x.push_back(c);
            while (x.size() >= 3 && x.substr(x.size() - 3) == "110")
            {
                count++;
                x.pop_back();x.pop_back();x.pop_back();
            }
        }
                
        int idx = -1;
        for (int i = x.size() - 1; i >= 0; i--)
        {
            if (x[i] == '0')
            {
                idx = i;
                break;
            }
        }
        idx++;
        
        string res(x.begin(), x.begin() + idx);
        for (int i = 0; i < count; i++)
        {
            res.append("110");
        }
        res.append(x.substr(idx));
        answer.push_back(res);
    }
    return answer;
}