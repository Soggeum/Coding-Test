#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    int zero = 0, cnt = 0;
    string::iterator new_end;

    while (s != "1") {
        new_end = remove(s.begin(), s.end(), '0');
        zero += s.end() - new_end;
        s.erase(new_end, s.end());
        cnt++;
    
        s = bitset<20>{s.size()}.to_string();
        s = s.substr(s.find('1'));
    }
    
    return {cnt, zero};
}
