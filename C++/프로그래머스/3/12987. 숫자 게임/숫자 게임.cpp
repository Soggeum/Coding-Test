#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    multiset<int> NewB;
    for (int b : B)
    {
        NewB.insert(b);
    }
    for (int a : A)
    {
        auto it = NewB.upper_bound(a);
        if (it != NewB.end())
        {
            answer++;
            NewB.erase(it);
        }
    }
    
    return answer;
}