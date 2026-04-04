#include <string>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2) {
    unordered_map<string, int> um1;
    string temp;
    int Add = 0;
    for (int i = 0; i < str1.size() - 1; i++)
    {
        temp = str1.substr(i, 2);
        if (isalpha(temp[0]) && isalpha(temp[1]))
        {
            temp[0] = tolower(temp[0]);
            temp[1] = tolower(temp[1]);
            um1[temp]++;
            Add++;
        }
    }
    
    int Cross = 0;
    unordered_map<string, int> um2;
    for (int i = 0; i < str2.size() - 1; i++)
    {
        temp = str2.substr(i, 2);
        if (isalpha(temp[0]) && isalpha(temp[1]))
        {
            temp[0] = tolower(temp[0]);
            temp[1] = tolower(temp[1]);
            if (um1[temp] == 0)
            {
                Add++;                
            }            
            else if (um1[temp] > um2[temp])
            {
                Cross++;
                um2[temp]++;
            }
            else
            {
                Add++; 
            }
        }
    }
    
    if (Add == 0)
    {
        return 65536;
    }
    
    int answer = Cross * 1.0 / Add * 65536;
    return answer;
}