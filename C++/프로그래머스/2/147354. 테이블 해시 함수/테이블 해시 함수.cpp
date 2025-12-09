#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b)
         {
             if (a[col - 1] != b[col - 1])
                 return a[col - 1] < b[col - 1];
             return a[0] > b[0];
         });
    
    int answer = 0;
    while (row_begin <= row_end) {
        int left = 0;
        for (int num : data[row_begin - 1]) {
            left += num % row_begin;
        }
        
        answer ^= left;
        row_begin++;
    }
    
    return answer;
}