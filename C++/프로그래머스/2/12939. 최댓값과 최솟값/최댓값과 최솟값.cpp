#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isBig(const string& a, const string& b)
{
    if ((a[0] != '-') && (b[0]) == '-')
        return true;
    if ((a[0] == '-') && (b[0]) != '-')
        return false;

    if ((a[0] == '-') && (b[0]) == '-') {
        if (a.length() != b.length())
            return (b.length() > a.length());

        return (b > a);
    }
    

    else {
        if (a.length() != b.length())
            return (a.length() > b.length());

        return (a > b);
    }

}

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string token;

    string min, max;
    getline(ss, min, ' ');
    max = min;
    

    while (getline(ss, token, ' '))
    {
        if (isBig(token, max))
            max = token;
        if (isBig(min, token))
            min = token;
    }

    answer.append(min);
    answer.append(" ");
    answer.append(max);
    return answer;
}