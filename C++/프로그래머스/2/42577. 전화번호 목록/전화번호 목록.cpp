#include <string>
#include <vector>
#include <algorithm>
#include <string_view>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i].size() < phone_book[i+1].size())
        {
            string_view sv(phone_book[i+1].data(), phone_book[i].size());
            if (phone_book[i] == sv)
            {
                return false;
            }
        }
    }
    
    return true;
}