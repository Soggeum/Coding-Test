#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    string Temp;
    for (int c = 1; c <= s.length(); c++)
    {
        vector<pair<string, int>> NewS;
        NewS.push_back({s.substr(0, c), 1});
        Temp.clear();
        for (int i = c; i < s.length(); i++)
        {
            Temp.push_back(s[i]);
            if (Temp.length() == c)
            {
                if (Temp == NewS.back().first)
                {
                    NewS.back().second++;
                }
                else
                {
                    NewS.push_back({Temp, 1});
                }        
                Temp.clear();            
            }
        }
        
        int len = 0;
        for (const auto p : NewS)
        {
            len += p.first.length();
            if (p.second > 1)
            {
                len += to_string(p.second).length();
            }
        }
        len += Temp.length();
        
        answer = min(answer, len);
    }
    
    return answer;
}