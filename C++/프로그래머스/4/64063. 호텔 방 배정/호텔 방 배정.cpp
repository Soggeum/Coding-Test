#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long GetRoom(long long rn, unordered_map<long long, long long>& Table)
{
    if (Table.find(rn) == Table.end())
    {
        Table[rn] = rn + 1;
        return rn;
    }
    
    return Table[rn] = GetRoom(Table[rn], Table);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> Table;
    vector<long long> answer;
    for (long long rn : room_number)
    {
        answer.push_back(GetRoom(rn, Table));
    }
    return answer;
}