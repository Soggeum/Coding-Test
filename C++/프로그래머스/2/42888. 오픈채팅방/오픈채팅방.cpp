#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, int>> logs;
    unordered_map<string, string> idToNickName;

    string did, id, nickname;
    for (const auto& sentence : record) {
        
        stringstream ss(sentence);
        ss >> did >> id >> nickname;
        
        if (did == "Enter") {
            logs.push_back({id, 0});
            idToNickName[id] = nickname;
        }
        else if (did == "Leave") {
            logs.push_back({id, 1});
        }
        else {
            idToNickName[id] = nickname;
        }
    }

    for (const auto& [id, behave] : logs) {
        string temp;
        temp.append(idToNickName[id]);
        if (behave == 0) {
            temp.append("님이 들어왔습니다.");
        }
        else {
            temp.append("님이 나갔습니다.");
        }
        answer.push_back(temp);
    }

    return answer;
}