#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (char& c : str)
    {
        if (islower(c))
        {
            c = toupper(c);
        }
        else
        {
            c = tolower(c);
        }
    }
    
    cout << str;
    
    return 0;
}