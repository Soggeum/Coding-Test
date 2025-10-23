#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

void DFS(string& CurrentNumber, unordered_map<char, int>& LeftCards, int len, unordered_set<int>& NumberSet) {
    for (auto& [Card, CardNum] : LeftCards) {
        if (CardNum == 0)
            continue;
        CardNum--;
        CurrentNumber.push_back(Card);
        NumberSet.insert(stoi(CurrentNumber));
        DFS(CurrentNumber, LeftCards, len + 1, NumberSet);

        CurrentNumber.pop_back();
        CardNum++;
    }
}

void MakeNumber(const string& numbers, unordered_set<int>& NumberSet) {
    unordered_map<char, int> LeftCards;
    for (char Card : numbers) {
        LeftCards[Card]++;
    }

    string CurrentNumber("");
    DFS(CurrentNumber, LeftCards, 0, NumberSet);
}

bool IsPrime(int Num) {
    if (Num == 0 || Num == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(Num); i++) {
        if (Num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> NumberSet;
    MakeNumber(numbers, NumberSet);

    int answer = 0;
    for (int Number : NumberSet) {
        if (IsPrime(Number))
            answer++;
    }
    return answer;
}