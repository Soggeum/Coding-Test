#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Node
{
    string Name;
    int Time;
    int Duration;
};

bool comp(const vector<string>& a, const vector<string>& b) {
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), comp);

    vector<Node> Plans;
    for (vector<string>& plan : plans)
    {
        int Minute = stoi(plan[1].substr(0, 2)) * 60 + stoi(plan[1].substr(3, 2));
        Plans.push_back({ plan[0], Minute, stoi(plan[2]) });
    }
    stack<Node> Stop;
    vector<string> answer;

    int i = 0, Cur = Plans[0].Time;
    Node Task;
    while (i < Plans.size() || !Stop.empty())
    {
        if (Cur == Plans[i].Time)
        {
            Stop.push({ Plans[i].Name, Plans[i].Time, Plans[i].Duration });
            i++;
        }

        while (!Stop.empty())
        {
            if (i == Plans.size())
            {
                while (!Stop.empty())
                {
                    answer.push_back(Stop.top().Name);
                    Stop.pop();
                }
                return answer;
            }

            Node& Top = Stop.top();
            Top.Time += 1;
            Top.Duration -= 1;
            Cur++;

            if (Top.Duration == 0)
            {
                answer.push_back(Top.Name);
                Stop.pop();
                if (Stop.empty())
                {
                    Cur = Plans[i].Time;
                    break;
                }
            }
            if (Cur == Plans[i].Time)
            {
                break;
            }
        }
    }

    return answer;
}