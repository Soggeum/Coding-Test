#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> Dic;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        Dic[string(1, c)] = c - 'A' + 1;
    }
    
    int out = 0, LastIndex = 26;
    for (int i = 0; i < msg.length();)
    {
        int j;
        for (j = 1; j <= msg.length() - i; j++)
        {
            string input = msg.substr(i, j);   
            if (Dic.find(input) != Dic.end())
            {
                out = Dic[input];
            }
            else
            {
                answer.push_back(out);
                LastIndex++;
                Dic[input] = LastIndex;
                i += j - 1;
                out = 0;
                break;
            }
        }
        if (out)
        {
            answer.push_back(out);
            i = msg.length();
        }
    }
    
    return answer;
}