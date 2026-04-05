#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> foods;
    for (const int& s : scoville)
    {
        foods.insert(s);
    }
    
    if (*foods.begin() >= K)
    {
        return 0;
    }
    
    while(foods.size() > 1)
    {
        int Lowest = *foods.begin();        
        foods.erase(foods.begin());
        int SecondLowest = *foods.begin();
        foods.erase(foods.begin());
        
        foods.insert(Lowest + 2 * SecondLowest);
        answer++;
        
        if (*foods.begin() >= K)
        {
            return answer;
        }
    }
    
    return -1;
}