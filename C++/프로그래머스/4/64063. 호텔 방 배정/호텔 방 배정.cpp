#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long GetRoom(long long rn, unordered_map<long long, long long>& um)
{
    auto it = um.find(rn);
    if (it == um.end())
    {
        um[rn] = rn + 1;
        return rn;
    }
    
    it->second = GetRoom(it->second, um);
    return it->second;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> um;
    vector<long long> answer;
    
    for (long long rn : room_number)
    {
        long long Room = GetRoom(rn, um);
        answer.push_back(Room);
    }
    
    return answer;
}