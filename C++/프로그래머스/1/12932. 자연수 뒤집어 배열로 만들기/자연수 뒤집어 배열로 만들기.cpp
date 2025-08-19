#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    string n_sv{ to_string(n) };
    vector<int> answer;
    for (int i = n_sv.size() - 1; i >= 0; i--) {
        answer.push_back(n_sv[i] - '0');
    }

    return answer;
}