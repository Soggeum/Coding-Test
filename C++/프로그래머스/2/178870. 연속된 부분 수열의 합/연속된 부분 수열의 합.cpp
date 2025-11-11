#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int low = 0, high = 0, n = sequence.size();
    int sum = sequence[0];
    vector<int> answer = {0, n - 1};
    while (low <= high && high < n) {
        if (sum < k) {
            high++;
            if (high >= n)
                break;
            sum += sequence[high];
        }
        else if (sum > k) {
            sum -= sequence[low];
            low++;
        }
        else {
            if (high - low < answer[1] - answer[0]) {
                answer[0] = low;
                answer[1] = high;
            }
            sum -= sequence[low];
            low++;
        }
    }
    
    return answer;
}