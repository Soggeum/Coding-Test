#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

int CountNode(const vector<vector<int>>& wires, const vector<int>& target_wire) {
    unordered_set<int> Tree;
    queue<int> q;
    q.push(target_wire[0]);
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (Tree.find(top) != Tree.end())
            continue;
        
        Tree.insert(top);
        for (const vector<int>& wire : wires) {
            if (wire == target_wire)
                continue;
            if (wire[0] == top)
                q.push(wire[1]);
            if (wire[1] == top)
                q.push(wire[0]);
        }
    }   
    
    return Tree.size();
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n, tree_num;
    for (const vector<int>& wire : wires) {
        tree_num = CountNode(wires, wire);
        answer = min(answer, abs((n - tree_num) - tree_num));
    }
    return answer;
}