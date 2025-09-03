#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> term_map;
    string k;
    int v;
    stringstream ss;

    for (const auto& term : terms) {
        ss.clear();
        ss.str("");
        ss.str(term);

        ss >> k >> v;
        term_map[k] = v;
    }

    string due_date;
    int year;
    int month;
    int date;
    int idx = 1;
    for (const auto& privacy : privacies) {
        year = stoi(string(privacy.begin(), privacy.begin() + 4));
        month = stoi(string(privacy.begin() + 5, privacy.begin() + 7)) + term_map[string(1, privacy.back())];
        if (month > 12) {
            year += (month - 1) / 12;
            month = (month - 1) % 12 + 1;
        }
        date = stoi(string(privacy.begin() + 8, privacy.begin() + 10)) - 1;
        if (date == 0) {
            date = 28;
            month--;
            if (month == 0) {
                year--;
                month = 12;
            }
        }

        due_date.assign(to_string(year));
        due_date.push_back('.');
        if (month < 10)
            due_date.push_back('0');
        due_date.append(to_string(month));
        due_date.push_back('.');
        if (date < 10)
            due_date.push_back('0');
        due_date.append(to_string(date));

        if (today > due_date)
            answer.push_back(idx);

        idx++;
    }

    return answer;
}
