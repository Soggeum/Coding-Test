#include <string>
#include <vector>

using namespace std;

int DFS(string& str, int n, int Left, int Right)
{
    if (Left == n && Right == n)
    {
        return 1;
    }
    if (Left < Right)
    {
        return 0;
    }
    if (Left > n || Right > n)
    {
        return 0;
    }
    
    int Res = 0;
    str.push_back('(');
    Res += DFS(str, n, Left + 1, Right);
    str.pop_back();
    
    str.push_back(')');
    Res += DFS(str, n, Left, Right + 1);
    str.pop_back();
    
    return Res;
}

int solution(int n) {
    string str = "";    
    return DFS(str, n, 0, 0);
}