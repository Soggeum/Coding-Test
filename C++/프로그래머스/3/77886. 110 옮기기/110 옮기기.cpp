#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (const string& x : s)
    {
        if (x.size() <= 3)
        {
            answer.push_back(x);
            continue;
        }
        
        string Temp = x.substr(0, 2);
        int Count = 0;
        for (int i = 2; i < x.size(); i++)
        {
            Temp.push_back(x[i]);
            while (Temp.size() >= 3 && string(Temp.end() - 3, Temp.end()) == "110")
            {
                Count++;
                Temp.pop_back();Temp.pop_back();Temp.pop_back();
            }
        }
        
        int LastZero = -1;
        for (int i = 0; i < Temp.size(); i++)
        {
            if (Temp[i] == '0')
            {
                LastZero = i;
            }
        }
        
        string res = string(Temp.begin(), Temp.begin() + LastZero + 1);
        for (int i = 0; i < Count; i++)
        {
            res.append("110");
        }
        res.append(string(Temp.begin() + LastZero + 1, Temp.end()));
        answer.push_back(res);
    }
    
    return answer;
}