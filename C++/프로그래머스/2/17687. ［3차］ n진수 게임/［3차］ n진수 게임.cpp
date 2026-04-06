#include <string>
#include <vector>

using namespace std;

string Convert(int Num, int n)
{
    string result;
    while (Num >= n)
    {
        int Left = Num % n;
        char L = (Left >= 10) ? 'A' + (Left - 10) : '0' + Left;
        result.push_back(L);
        Num /= n;
    }
    char L = (Num >= 10) ? 'A' + (Num - 10) : '0' + Num;
    result.push_back(L);
    
    return string(result.rbegin(), result.rend());
}

string solution(int n, int t, int m, int p) {
    int size = (t - 1) * m + p; 
    string AllNum;
    int Num = 0;
    while (AllNum.length() < size)
    {
        AllNum.append(Convert(Num, n));  
        Num++;
    }
    
    string answer;
    for (int i = p - 1, cnt = 0; cnt < t; i += m, cnt++)
    {
        answer.push_back(AllNum[i]);
    }
    return answer;
}