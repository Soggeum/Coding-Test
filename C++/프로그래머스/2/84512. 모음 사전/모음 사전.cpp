#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int PreWordCnt(char first_char, int num) {
    static unordered_map<char, int> order = {{'A', 0},{'E', 1},{'I', 2},{'O',3},{'U', 4}};    

    return order[first_char] * (pow(5, num + 1) - 1) / 4;
}

int solution(string word) {    
    int answer = 0;
    for (int i = 0; i < word.length(); i++) {
        answer += PreWordCnt(word[i], 5 - i - 1);
        answer++;
    }
    return answer;
}