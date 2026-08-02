#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long GetParent(unordered_map<long long, long long>& Rooms, long long n)
{
    if (Rooms.find(n) == Rooms.end())
    {
        Rooms[n] = n + 1;
        return n;
    }
    
    return Rooms[n] = GetParent(Rooms, Rooms[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> Rooms;
    vector<long long> answer;
    
    for (long long rn : room_number)
    {
        answer.push_back(GetParent(Rooms, rn));
    }
    
    return answer;
}