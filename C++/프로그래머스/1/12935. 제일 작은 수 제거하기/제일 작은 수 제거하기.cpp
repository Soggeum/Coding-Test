#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1)
        return vector<int>{-1};
    
    auto it = min_element(arr.begin(), arr.end());
    arr.erase(it);

    
    return arr;
}