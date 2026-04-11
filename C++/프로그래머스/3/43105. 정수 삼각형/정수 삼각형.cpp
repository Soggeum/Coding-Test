#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int FromLeft = 0, FromRight = 0;
            if (j > 0)
            {
                FromLeft = triangle[i - 1][j - 1];
            }
            if (j < triangle[i - 1].size())
            {
                FromRight = triangle[i - 1][j];
            }
            triangle[i][j] += max(FromLeft, FromRight);
            answer = max(answer, triangle[i][j]);
        }
    }
    return answer;
}