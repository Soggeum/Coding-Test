#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    int pulse = 1;
    for (int& num : sequence)
    {
        num *= pulse;
        pulse *= -1;
    }
    
    long long MaxSum = sequence[0], CurrentSum = sequence[0];
    for (int i = 1; i < sequence.size(); i++)
    {
        CurrentSum += sequence[i];
        if (CurrentSum < sequence[i])
        {
            CurrentSum = sequence[i];
        }
        MaxSum = max(MaxSum, CurrentSum);
    }
    
    for (int& num : sequence)
    {
        num *= -1;
    }
    CurrentSum = sequence[0];
    MaxSum = max(MaxSum, CurrentSum);
    for (int i = 1; i < sequence.size(); i++)
    {
        CurrentSum += sequence[i];
        if (CurrentSum < sequence[i])
        {
            CurrentSum = sequence[i];
        }
        MaxSum = max(MaxSum, CurrentSum);
    }
    
    return MaxSum;
}