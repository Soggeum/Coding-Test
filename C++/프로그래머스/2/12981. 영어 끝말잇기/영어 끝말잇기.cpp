#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> speak = {words[0]};
    
    for (int i = 1; i < words.size(); i++) {
        const string& word = words[i];    
        if ((speak.find(word) != speak.end()) || (words[i][0] != words[i-1].back())) {
            answer[0] = (i % n + 1);
            answer[1] = (i / n + 1);
            break;
        }   
        speak.insert(word);
    }

    return answer;
}