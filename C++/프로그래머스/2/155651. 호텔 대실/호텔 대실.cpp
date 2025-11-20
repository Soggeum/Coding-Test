#include <string>
#include <vector>

using namespace std;

int TimeToMinute(const string& Time) {
    int time = stoi(Time.substr(0, 2));
    int minute = stoi(Time.substr(3, 2));
    
    return time * 60 + minute;
}

int NeedRoom(int time, const vector<vector<string>>& book_time) {
    int result = 0;
    for (const vector<string>& Reservation : book_time) {
        int Start = TimeToMinute(Reservation[0]);
        int End = TimeToMinute(Reservation[1]) + 10;
        if (Start <= time && time < End)
            result++;
    }
    
    return result;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for (int i = TimeToMinute("00:00"); i < TimeToMinute("24:00"); i++) {
        int RoomCnt = NeedRoom(i, book_time);
        answer = max(answer, RoomCnt);
    }
    
    return answer;
}