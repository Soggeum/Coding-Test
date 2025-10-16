#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> Cnt;
    int ToppingTypes = 0;
    for (const int& EachTopping : topping) {
        if (Cnt[EachTopping] == 0)
            ToppingTypes++;
        Cnt[EachTopping]++;
    }
    
    int Answer = 0;
    unordered_set<int> ChulSuToppingType;
    int BrotherToppingType = ToppingTypes;
    for (const int& EachTopping : topping) {
        ChulSuToppingType.insert(EachTopping);
        
        Cnt[EachTopping]--;
        if (Cnt[EachTopping] == 0) {
            BrotherToppingType--;
        }
        
        if (ChulSuToppingType.size() == BrotherToppingType)
            Answer++;
    }
    return Answer;
}