#include <string>
#include <vector>
#include <queue>

using namespace std;

struct InData
{
    int X;
    int Answer;
};

int solution(int x, int y, int n) {
    queue<struct InData> q;
    q.push({x, 0});
    
    vector<int> MinAnswer(1000000, 1000000);
    int X, Answer;
    while(!q.empty()) {
        X = q.front().X;
        Answer = q.front().Answer;
        q.pop();
        
        if (X == y)
            return Answer;
        
        if ((X * 3 <= y) && (Answer + 1 < MinAnswer[X * 3 - 1])) {
            q.push({X * 3, Answer + 1});
            MinAnswer[X * 3 - 1] = Answer + 1;
        }
        if ((X * 2 <= y) && (Answer + 1 < MinAnswer[X * 2 - 1])) {
            q.push({X * 2, Answer + 1});
            MinAnswer[X * 2 - 1] = Answer + 1;
        }
        if ((X + n <= y) && (Answer + 1 < MinAnswer[X + n - 1])) {
            q.push({X + n, Answer + 1});
            MinAnswer[X + n - 1] = Answer + 1;
        }
    }
    
    return -1;
}