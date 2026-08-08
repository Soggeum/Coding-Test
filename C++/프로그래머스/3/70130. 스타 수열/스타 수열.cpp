#include <string>
#include <vector>

// Last에 각 숫자가 스타수열에 들어갔을 때 가장 마지막으로 사용된 수의 인덱스 넣기
// 이전 숫자가 되면 넣기, 안 되면 다음 숫자.

using namespace std;

int solution(std::vector<int> a) {
    vector<int> Last(a.size(), -1);
    vector<int> Count(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        if (Last[a[i]] != i - 1 && a[i - 1] != a[i])
        {
            Last[a[i]] = i;
            Count[a[i]] += 2;
        }
        else if (i + 1 < a.size() && a[i + 1] != a[i])
        {
            Last[a[i]] = i + 1;
            Count[a[i]] += 2;
        }
        else
        {
            Last[a[i]] = i;
        }
    }
    int answer = 0;
    for (int n : Count)
    {
        answer = max(answer, n);
    }
    return answer == 2 ? 0  : answer;
}