#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cmath>

using namespace std;

int GetMinute(const string& InTime, const string& OutTime) {
    int InHour = stoi(InTime.substr(0, 2));
    int InMinute = stoi(InTime.substr(3, 2));
    int OutHour = stoi(OutTime.substr(0, 2));
    int OutMinute = stoi(OutTime.substr(3, 2));
    
    return (OutHour * 60 + OutMinute) - (InHour * 60 + InMinute);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> total_time;
    unordered_map<string, string> in_time;
    int base_time = fees[0];
    int base_fee = fees[1];
    int per_time = fees[2];
    int per_fee = fees[3];
    
    string park_time, number, condition;
    vector<int> answer;
    for (const string& record : records){
        stringstream ss(record);
        ss >> park_time >> number >> condition;
        
        if (condition == "IN")
        {
            in_time[number] = park_time;
        }
        
        else
        {
            total_time[number] += GetMinute(in_time[number], park_time);
            in_time[number] = string("OUT");
        }
    }
    
    for (auto& [number, InTime] : in_time) {
        if (InTime != string("OUT"))
        {
            total_time[number] += GetMinute(InTime, string("23:59"));
            InTime = string("OUT");
        }
    }
    
    for (const auto& [Number, TotalTime] : total_time) {
        if (TotalTime > base_time)
            answer.push_back(base_fee + ceil(1.0 * (TotalTime - base_time) / per_time) * per_fee);
        else 
            answer.push_back(base_fee);
    }
    
    
    return answer;
}