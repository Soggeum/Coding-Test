#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPossible(string word, unordered_map<string, int>& table)
{
    string temp;
    for (char c: word) {
        temp.push_back(c);
        if (temp.size() > 3)
            return false;
        
        if (table.find(temp) != table.end()) {
            if (table[temp] == 1)
                return false;
            else {
                for (auto& pair: table) {
                    pair.second = 0;
                }
                table[temp] = 1;
                temp.clear();
            }
        }
    }
    
    if (temp.empty())
        return true;
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    unordered_map<string, int> table;
    
    for (string word : babbling) {
        table["aya"] = 0;
        table["ye"] = 0;
        table["woo"] = 0;
        table["ma"] = 0;
        
        if (isPossible(word, table))
            answer++;
    }
    return answer;
}