#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

bool isOkay(int i, const vector<string>& want, const vector<int>& number, 
            const vector<string>& discount) 
{
    for (int j = 0; j < want.size(); j++) {
        if (count(discount.begin() + i, discount.begin() + i + 10, want[j]) != number[j]) 
            return false;  
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int sale_date = discount.size();
    
    for (int i = 0; i < sale_date - 9; i++) {
        if (isOkay(i, want, number, discount)) 
            answer++;
    }
    
    return answer;
}