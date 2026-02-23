#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int n;
    
    cin >> str >> n;
    
    string s;
    for (int i = 0; i < n; i++)
    {
        s.append(str);
    }
    cout << s;
    
    return 0;
}