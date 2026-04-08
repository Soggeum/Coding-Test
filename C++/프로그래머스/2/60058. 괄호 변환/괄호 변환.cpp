#include <string>
#include <vector>

using namespace std;

bool IsRight(const string& u)
{
    int cnt = 0;
    for (char c : u)
    {
        cnt += c == '(' ? 1 : -1;
        if (cnt < 0)
        {
            return false;
        }
    }
    return true;
}

string FourthFourth(const string& u)
{
    string res;
    for (int i = 1; i < u.size() - 1; i++)
    {
        res.push_back(u[i] == '(' ? ')' : '(');
    }
    return res;
}

string solution(string p) {
    if (p.empty())
    {
        return p;
    }
    
    string u, v;
    int Bias = 0;
    for (int i = 0; i < p.size(); i++)
    {
        u.push_back(p[i]);
        Bias += p[i] == '(' ? 1 : -1;
        if (Bias == 0)
        {
            v = p.substr(i + 1);
            break;
        }
    }
    
    if (IsRight(u))
    {
        string NewV = solution(v);
        return u + NewV;
    }
    else
    {
        string res = "(";
        res.append(solution(v));
        res.push_back(')');
        res.append(FourthFourth(u));
        return res;
    }
}