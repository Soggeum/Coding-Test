#include <string>
#include <vector>
#include <set>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    multiset<int> Table;
    for (int w : works)
    {
        Table.insert(w);
    }
    
    while (n)
    {
        int Back = *Table.rbegin();
        if (Back == 0)
        {
            return 0;
        }
        Table.erase(--Table.end());
        Back--;
        Table.insert(Back);        
        
        n--;
    }
    for (int w : Table)
    {
        answer += w * w;
    }
    return answer;
}