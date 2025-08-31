#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n, 1);
    for (int i: lost)
        clothes[i - 1]--;
    for (int i: reserve)
        clothes[i - 1]++;
    
    if ((clothes[0] == 2) && (clothes[1] == 0))
        clothes[0] = clothes[1] = 1;
    if ((clothes[n - 1] == 2) && (clothes[n - 2] == 0))
        clothes[n - 1] = clothes[n - 2] = 1;
    
    for (int i = 1; i < n - 1; i++) {
        if (clothes[i] == 2) {
            if (clothes[i - 1] == 0) {
                clothes[i]--;
                clothes[i - 1]++;
            }
            else if (clothes[i + 1] == 0) {
                clothes[i]--;
                clothes[i + 1]++;
            }  
        }
    }
    
    return (n - count(clothes.begin(), clothes.end(), 0));
}