#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int m = arr1.size(), n = arr2[0].size();
    vector<vector<int>> answer(m, vector<int>(n));
    vector<int> temp(n);
    int sum = 0;
    
    for (int row = 0; row < arr1.size(); row++) {
        for (int col = 0; col < arr2[0].size(); col++) {
            for (int i = 0; i < arr1[0].size(); i++) {
                sum += arr1[row][i] * arr2[i][col];
            }
            answer[row][col] = sum;
            sum = 0;
        }
    }
    
    
    return answer;
}