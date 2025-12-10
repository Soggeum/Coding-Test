#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Hanoii(int n, int start, int end, int mid)
{
    if (n == 1)
        return {{start, end}};
    
    vector<vector<int>> result = Hanoii(n - 1, start, mid, end);
    result.push_back({start, end});
    
    vector<vector<int>> later = Hanoii(n - 1, mid, end, start);
    for(vector<int> pair : later) {
        result.push_back(pair);
    }
    return result;
}

vector<vector<int>> solution(int n) {
    return Hanoii(n, 1, 3, 2);
}