#include <string>
#include <vector>

using namespace std;

int DFS(int cnt, int k, const int& N, vector<int>& visit, const vector<vector<int>>& dungeons) {
    int temp, max = cnt;
    for (int i = 0; i < N; i++) 
    {
        if ((visit[i] == 0) && (k >= dungeons[i][0]))
        {
            visit[i] = 1;
            temp = DFS(cnt + 1, k - dungeons[i][1], N, visit, dungeons);
            max = temp > max ? temp : max;
            
            visit[i] = 0;
        }
    }
    
    return max;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0, N = dungeons.size();
    vector<int> visit(N, 0);
    
    return DFS(0, k, N, visit, dungeons);
}