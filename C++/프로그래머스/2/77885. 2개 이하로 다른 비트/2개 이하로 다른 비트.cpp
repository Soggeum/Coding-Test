#include <string>
#include <vector>
#include <cmath>

using namespace std;

string ToBit(long long num, int& ZeroIdx) {
    string NumBit;
    int Idx = 0;
    while (num >= 1) {
        NumBit.push_back(num % 2 + '0');

        if ((ZeroIdx == -1) && (num % 2 == 0)) {
            ZeroIdx = Idx;            
        }
        
        num /= 2;
        Idx++;
    }
    NumBit.push_back('0');
    
    if (ZeroIdx == -1)
        ZeroIdx = Idx;
    
    NumBit = string(NumBit.rbegin(), NumBit.rend()); 
    
    return NumBit;    
}

long long BitToLong(string NumBit) {    
    long long result = 0;
    for (int i = 0; i < NumBit.length(); i++) {
        result += (NumBit[i] - '0') * pow(2, NumBit.length() - 1 - i);
    }
    return result;
}

long long Answer(long long num) {
    int ZeroIdx = -1;
    string NumBit(ToBit(num, ZeroIdx));
    
    if (ZeroIdx == 0) {
        *NumBit.rbegin() = '1';
    }
    else {
        *(NumBit.rbegin() + ZeroIdx) = '1';
        *(NumBit.rbegin() + ZeroIdx - 1) = '0';
    }
    
    return BitToLong(NumBit);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long number : numbers) {
        answer.push_back(Answer(number));
    }
    return answer;
}