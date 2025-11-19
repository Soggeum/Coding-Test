#include <vector>
#include <unordered_map>

using namespace std;

void BackTracking(const vector<unordered_map<int, int>>& Edge, vector<int>& visit, int from, int Time, int K) {
    for (auto it = Edge[from].begin(); it != Edge[from].end(); it++) {
        int to = it->first, w = it->second;
        if ((Time + w <= K) && (visit[to] > Time + w)) {
            visit[to] = Time + w;
            BackTracking(Edge, visit, to, Time + w, K);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    vector<unordered_map<int, int>> Edge(N + 1);
    for (const vector<int>& elem : road) {
        int a = elem[0], b = elem[1], c = elem[2];
        if (Edge[a][b] == 0)
            Edge[a][b] = c;
        else 
            Edge[a][b] = min(Edge[a][b], c);
        
        if (Edge[b][a] == 0)
            Edge[b][a] = c;
        else 
            Edge[b][a] = min(Edge[b][a], c);
    }
    
    vector<int> visit(N + 1, 5000000);
    visit[1] = 0;
    BackTracking(Edge, visit, 1, 0, K);
    
    int answer = 0;
    for (int i = 1; i < visit.size(); i++) {
        if (visit[i] <= K)
            answer++;
    }
    return answer;
}