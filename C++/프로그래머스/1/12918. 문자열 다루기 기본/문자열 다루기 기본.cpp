#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if ((s.size() != 4) && (s.size() != 6))
        return false;
    
    for (char x : s) {
        if ((x < '0') || (x > '9'))
            return false;
    }
    return true;
}