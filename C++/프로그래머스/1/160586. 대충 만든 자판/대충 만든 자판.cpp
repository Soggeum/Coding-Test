#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, pair<int, int>> alphabet;
    
    for(int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            if ( (!alphabet[keymap[i][j]].second) || ( (j + 1) < alphabet[keymap[i][j]].second) )
                alphabet[keymap[i][j]] = {i + 1, j + 1};
        }
    }
    
    int count;
    for (auto target: targets) {
        count = 0;
        for (auto c: target) {
            if (!alphabet[c].second) {
                count = -1;
                break;
            }
            
            count += alphabet[c].second;
        }
        answer.push_back(count);
    }
    
    return answer;
}