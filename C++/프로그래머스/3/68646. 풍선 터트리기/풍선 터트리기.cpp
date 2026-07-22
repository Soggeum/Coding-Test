#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> a) {
    if (a.size() < 3)
    {
        return a.size();        
    }
    
    set<int> Left = {a[0]}, Right;
    for (int i = 2; i < a.size(); i++)
    {
        Right.insert(a[i]);
    }
    
    int answer = 2;
    for (int i = 1; i < a.size() - 1; i++)
    {
        int MinLeft = *Left.begin(), MinRight = *Right.begin();
        if (!(a[i] > MinLeft && a[i] > MinRight))
        {
            answer++;
        }
        
        Left.insert(a[i]);
        Right.erase(a[i + 1]);
    }
    return answer;
}