#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (char c : name)
    {
        answer += min(c - 'A', 'Z' - c + 1);
    }
    
    int Move = name.size() - 1;
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A')
        {
            int LastA = i;
            while (LastA < name.size() && name[LastA] == 'A')
            {
                LastA++;
            }
            int opt1 = 2 * max(0, i-1) + name.size() - LastA;
            int opt2 = 2 * (name.size() - LastA) + max(0 ,  i - 1);
            Move = min(Move, min(opt1, opt2));
        }
    }
    return answer + Move;
}