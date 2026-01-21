// 명령어 3가지
// 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]
// 둘 이상인 경우, 하나만 삭제
// 빈 큐에 삭제하라는 연산이 주어질 경우, 해당 연산은 무시

#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for (const string& operation : operations)
    {
        stringstream ss(operation);
        string op;
        int data;
        ss >> op >> data;
                
        if (op == "I")
        {
            ms.insert(data);
        }
        else
        {
            if (ms.size() == 0) continue;
            if (data == 1)
            {
                ms.erase(prev(ms.end()));
            }
            else
            {
                ms.erase(ms.begin());
            }
        }
    }
    
    if (ms.size() == 0) return {0, 0};
    return {*(ms.rbegin()), *(ms.begin())};
}