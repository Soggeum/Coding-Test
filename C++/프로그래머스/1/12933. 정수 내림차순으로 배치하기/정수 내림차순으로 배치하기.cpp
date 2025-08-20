#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b) { return a > b;}

long long solution(long long n) {
    string n_s {to_string(n)};
    sort(n_s.begin(), n_s.end(), compare);
    return stol(n_s);
}