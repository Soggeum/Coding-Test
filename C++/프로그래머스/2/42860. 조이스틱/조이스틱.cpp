#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (char c : name)
    {
        answer += min(c - 'A', 'Z' - c + 1);
    }
    
    int Len = name.size() - 1;
    for (int i = 0; i < name.size(); i++)
    {
        int NextA = i + 1;
        while (NextA < name.size() && name[NextA] == 'A')
        {
            NextA++;
        }
        
        int opt1 = 2 * i + name.size() - NextA;
        int opt2 = 2 * (name.size() - NextA) + i;
        Len = min(Len, min(opt1, opt2));
    }
    
    
    return answer + Len;
}