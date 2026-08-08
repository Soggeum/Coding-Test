#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> Table(info.size(), vector<int>(m, n));
    if (info[0][0] < n)
    {
        Table[0][0] = info[0][0];        
    }
    if (info[0][1] < m)
    {
        Table[0][info[0][1]] = 0;
    }
    
    for (int i = 1; i < info.size(); i++)
    {
        int A = info[i][0], B = info[i][1];
        for (int j = 0; j < m; j++)
        {
            int opt1 = j - B >= 0 ? Table[i - 1][j - B] : n;
            int opt2 = min(Table[i - 1][j] + A, n);
            Table[i][j] = min(opt1, opt2);
        }
    }
    
    int answer = n;
    for (int x : Table.back())
    {
        if (x != n)
        {
            answer = min(answer, x);
        }
    }
    return answer == n ? -1 : answer;
}