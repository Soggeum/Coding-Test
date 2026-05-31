// Union-Find와 경로 압축 (lazy Optimization)
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long GetNextRoom(long long Request, unordered_map<long long, long long>& NextRoomMap)
{
    vector<long long> Visited;
    Visited.push_back(Request);
    
    auto it = NextRoomMap.find(Request);
    while(it != NextRoomMap.end())
    {
        Visited.push_back(Request);
        Request = it->second;
        it = NextRoomMap.find(Request);
    }
    Visited.push_back(Request);
    
    for (long long RoomNumber : Visited)
    {
        NextRoomMap[RoomNumber] = Request + 1;
    }
    
    return Request;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> NextRoomMap;
    for (long long Request : room_number)
    {
        if (NextRoomMap.count(Request))
        {
            long long NextRoom = GetNextRoom(Request, NextRoomMap);
            answer.push_back(NextRoom);
        }
        else
        {
            answer.push_back(Request);
            NextRoomMap[Request] = Request + 1;
        }
    }
    
    return answer;
}