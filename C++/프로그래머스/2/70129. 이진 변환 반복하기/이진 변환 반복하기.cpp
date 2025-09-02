#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void new_str(string& s)
{
	int len = s.length();
	string temp = "";
    while (len) {
        temp.push_back(len % 2 + '0');
		len /= 2;
	}
	
	s = string(temp.rbegin(), temp.rend());
}

vector<int> solution(string s) {
    int zero = 0, cnt = 0;
    string::iterator new_end;

    while (s != "1") {
        new_end = remove(s.begin(), s.end(), '0');
        zero += s.end() - new_end;
        s.erase(new_end, s.end());
        cnt++;

        new_str(s);
    }
    
    return {cnt, zero};
}
