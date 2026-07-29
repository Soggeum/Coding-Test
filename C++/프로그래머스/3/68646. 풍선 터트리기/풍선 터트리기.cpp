#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> a) {
    if (a.size() < 3)
    {
        return a.size();
    }
    int answer = 2, FrontSmall = a[0];
    set<int> Back;
    for (int i = 2; i < a.size(); i++)
    {
        Back.insert(a[i]);
    }
    
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (!(a[i] > FrontSmall && a[i] > *Back.begin()))
        {
            answer++;
        }
        FrontSmall = min(FrontSmall, a[i]);
        Back.erase(a[i + 1]);
    }
    
    
    return answer;
}