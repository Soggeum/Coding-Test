#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string table;
    for (int x : ingredient) {
        table.append(to_string(x));
        if ((table.size() >= 4) && (table.substr(table.size() - 4) == "1231")) {
            answer++;
            for (int i = 0; i < 4; i++) table.pop_back();
        }
    }
    return answer;
}