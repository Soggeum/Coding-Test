#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const char& a, const char& b) 
{
    if ((a < 'A') && (b >= 'A'))
        return true;
    return a > b;
}

string solution(string s) {
    sort(s.begin(), s.end(), comp);
    return s;
}