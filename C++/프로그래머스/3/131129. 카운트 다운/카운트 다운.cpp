#include <string>
#include <vector>

using namespace std;

struct Node
{
    int ThrowCount = 99999999, SB  = 99999999;
};

vector<int> solution(int target) {
    vector<int> SingleBull = {1, 2, 3, 4, 5, 6, 7, 8,9, 10,11,12,13,14,15,16,17,18,19,20, 50};
    vector<int> DoubleTriple;
    for (int n = 21; n <= 60; n++)
    {
        if (n % 2 == 0 && n / 2 <= 20)
        {
            DoubleTriple.push_back(n);
        }
        else if (n % 3 == 0 && n / 3 <= 20)
        {
            DoubleTriple.push_back(n);
        }
            
    }
    vector<Node> score(target + 1);
    score[0] = {0, 0};
    for (int i = 0; i < target; i++)
    {
        for (int sb : SingleBull)
        {
            if(i + sb <= target)
            {
                if (score[i + sb].ThrowCount > score[i].ThrowCount + 1)
                {
                    score[i+sb] = {score[i].ThrowCount + 1, score[i].SB + 1};
                }
                else if (score[i + sb].ThrowCount == score[i].ThrowCount + 1)
                {
                    score[i+sb].SB = max(score[i].SB + 1, score[i + sb].SB);
                }
            }
        }
        
        for (int dt : DoubleTriple)
        {
            if(i + dt <= target)
            {
                if (score[i + dt].ThrowCount > score[i].ThrowCount + 1)
                {
                    score[i+dt] = {score[i].ThrowCount + 1, score[i].SB};
                }
                else if (score[i + dt].ThrowCount == score[i].ThrowCount + 1)
                {
                    score[i+dt].SB = max(score[i].SB, score[i + dt].SB);
                }
            }
        }
    }
    
    return {score[target].ThrowCount, score[target].SB};
}