#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, unordered_set<string>> reportTable;
    unordered_map<string, int> count;
    unordered_set<string> ban;
    vector<int> answer;

    for (auto name : id_list) {
        reportTable[name] = {};
    }

    string from, to;
    for (string text : report) {
        std::istringstream iss(text);
        iss >> from >> to;
        if (reportTable[from].find(to) == reportTable[from].end()) {
			count[to]++;
            reportTable[from].insert(to);
		}
    }

    for (auto it : count) {
        if (it.second >= k) {
            ban.insert(it.first);
        }
	}

    int cnt;
    for (int i = 0; i < id_list.size(); i++) {
        cnt = 0;
        for (string name : reportTable[id_list[i]]) {
            if (ban.find(name) != ban.end()) {
                cnt++;
			}
        }
		answer.push_back(cnt);
    }

    return answer;
}