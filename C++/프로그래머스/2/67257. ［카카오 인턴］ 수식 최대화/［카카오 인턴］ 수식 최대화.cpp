#include <string>
#include <vector>
#include <list>

using namespace std;

const static vector<string> OpOrders = {"+-*", "+*-", "-+*", "-*+", "*-+", "*+-"};

long long Calc(list<string> exp, const string& OpOrder)
{
    for (char Op : OpOrder)
    {
        for (auto it = exp.begin(); it != exp.end(); it++)
        {
            if ((*it).size() == 1 && (*it)[0] == Op)
            {
                auto Prev = --it;
                ++it;
                auto Fore = ++it;
                --it;
                long long Result;
                
                switch(Op)
                {
                    case '+' :
                        Result = stoll(*Prev) + stoll(*Fore);
                        break;
                    case '-' :
                        Result = stoll(*Prev) - stoll(*Fore);
                        break;
                    default:
                        Result = stoll(*Prev) * stoll(*Fore);                        
                }
                
                *Prev = to_string(Result);
                exp.erase(it);
                exp.erase(Fore);
                it = Prev;
            }
        }
    }
    
    long long Result = stoll(*exp.begin());
    return Result < 0 ? -Result : Result;
}

long long solution(string expression) {
    list<string> exp;
    string temp;
    for (char c : expression)
    {
        if (isdigit(c))
        {
            temp.push_back(c);
        }
        else
        {
            exp.push_back(temp);
            temp.clear();
            exp.push_back(string(1, c));
        }
    }
    exp.push_back(temp);
    
    long long answer = 0;
    for (const string& OpOrder : OpOrders)
    {
        long long Result = Calc(exp, OpOrder);
        answer = max(answer, Result);
    }
    
    return answer;
}