#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string star(phone_number.size() - 4, '*');
    string back_number(phone_number, phone_number.size() - 4, 4);
    return star + back_number;
}