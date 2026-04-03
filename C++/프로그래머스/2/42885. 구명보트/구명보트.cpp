#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());    
    int answer = 0, low = 0, high = people.size() - 1, left;
    
    while (low <= high)
    {
        left = limit - people[high];
        high--;
        if (left >= people[low])
        {
            low++;
        }
        answer++;
    }
    
    return answer;
}