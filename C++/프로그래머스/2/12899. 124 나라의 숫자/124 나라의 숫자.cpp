#include <string>
#include <vector>

//  1   1
//  2   2
//  10  4
//  11  11
//  12  12
//  20  14

//  100 24

// 101  41

using namespace std;

string MakeThree(int n)
{
    string Res;
    while (n)
    {
        int Remainder = n % 3;
        if (Remainder)
        {
            Res.push_back(n % 3 + '0');
            n /= 3;
        }
        else
        {
            Res.push_back('4');
            n /= 3;
            n--;
        }
        
    }
    return string(Res.rbegin(), Res.rend());
}

string solution(int n) {
    string Three = MakeThree(n);
    return Three;
}