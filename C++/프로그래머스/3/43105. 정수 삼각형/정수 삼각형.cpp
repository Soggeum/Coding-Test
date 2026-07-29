#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];                
            }
            else if (j == triangle[i].size() - 1)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);                    }
        }
    }
    
    int answer = 0;
    for (int n : triangle.back())
    {
        answer = max(answer, n);
    }
    return answer;
}