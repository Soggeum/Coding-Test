#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> a) {
    if (a.size() < 3)
    {
        return a.size();
    }
    
    set<int> Right;
    for (int i = 2; i < a.size(); i++)
    {
        Right.insert(a[i]);
    }
    
    int answer = 2, Left = a[0];
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (!(Left < a[i] && a[i] > *Right.begin()))
        {
            answer++;
        }
        Left = min(Left, a[i]);
        Right.erase(a[i]);
        
    }
    return answer;
}