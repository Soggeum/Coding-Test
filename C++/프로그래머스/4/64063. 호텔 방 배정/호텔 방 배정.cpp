#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long GetRoomNumber(long long n, unordered_map<long long, long long>& um)
{
    if (um.find(n) == um.end())
    {
        um[n] = n + 1;
        return n;
    }
    
    long long RoomNumber = GetRoomNumber(um[n], um);
    um[n] = RoomNumber + 1;
    return RoomNumber;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> um;
    for (long long n : room_number)
    {
        answer.push_back(GetRoomNumber(n, um));
    }
    
    return answer;
}