#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

#include <iostream>

using namespace std;

int PreWordCnt(char first_char, int num) {
    static unordered_map<char, int> order = {{'A', 0},{'E', 1},{'I', 2},{'O',3},{'U', 4}};
    if (num == 0)
        return order[first_char];
    
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result += pow(5, i);
    }
    return order[first_char] * result;
}

int solution(string word) {    
    int answer = 0;
    for (int i = 0; i < word.length(); i++) {
        answer += PreWordCnt(word[i], 5 - i - 1);
        answer++;
        cout << answer << endl;
    }
    return answer;
}