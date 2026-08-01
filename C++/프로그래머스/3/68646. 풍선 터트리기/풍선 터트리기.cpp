#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> a) {
    if (a.size() < 3)
    {
        return a.size();
    }
    
    int answer = 2;
    set<int> Right;
    for (int i = 1; i < a.size(); i++)
    {
        Right.insert(a[i]);
    }
    int MinLeft = a[0];
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (!(MinLeft < a[i] && *Right.begin() < a[i]))
        {
            answer++;
        }
        MinLeft = min(MinLeft, a[i]);
        Right.erase(a[i]);
    }
    
    return answer;
}