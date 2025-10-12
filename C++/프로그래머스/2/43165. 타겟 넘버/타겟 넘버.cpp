#include <string>
#include <vector>

using namespace std;

static int answer;
static vector<int> numbers;
static int target;

void DFS(int idx, int result)
{   
    if (idx >= numbers.size())
    {
        if (result == target) {
            answer++;
        }
        return;
    }
    DFS(idx + 1, result + numbers[idx]);
    DFS(idx + 1, result - numbers[idx]);
}

int solution(vector<int> In_numbers, int In_target) {
    answer = 0;
    numbers = In_numbers;
    target = In_target;
    
    DFS(0, 0);
    
    return answer;
}