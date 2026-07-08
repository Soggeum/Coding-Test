#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& numbers, const int& target, int& idx, int& sum, int& answer)
{
    if (idx == numbers.size())
    {
        if (sum == target)
        {
            answer++;          
        }
        return;
    }
    
    sum += numbers[idx];
    idx++;
    DFS(numbers, target, idx, sum, answer);
    idx--;
    sum -= numbers[idx] * 2;
    idx++;
    DFS(numbers, target, idx, sum, answer);
    idx--;
    sum += numbers[idx];
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int idx = 0, sum = 0;
    DFS(numbers, target, idx, sum, answer);
    return answer;
}