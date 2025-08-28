#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> calendar {"SUN" , "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> date {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day{0};
    
    for (int i = 0; i < a - 1; i++)
        day += date[i];
    day += b;
    
    return calendar[(day + 4) % 7];
}