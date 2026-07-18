#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++)
    {
        int j = 0;
        triangle[i][j] += triangle[i - 1][j];
        for (j = 1; j < triangle[i].size() - 1; j++)
        {
            int FromLeft = triangle[i - 1][j - 1], FromRight = triangle[i - 1][j];
            triangle[i][j] += max(FromLeft, FromRight);
        }
        triangle[i][j] += triangle[i - 1][j - 1];
    }
    
    int answer = 0;
    for (int i = 0; i < triangle.back().size(); i++)
    {
        answer = max(triangle.back()[i], answer);
    }
    return answer;
}