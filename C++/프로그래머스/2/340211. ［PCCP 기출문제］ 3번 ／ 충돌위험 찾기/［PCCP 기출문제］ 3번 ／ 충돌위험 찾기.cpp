#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

// 로봇 위치 저장할 Robots 벡터
// 매 시간마다 이동하고 해당 좌표를 unordered map에 저장해서 다 이동하면 2개 이상인 개수만 세기

using namespace std;

struct Robot
{
    int r, c;
    queue<int> Dest;
    
    Robot(const vector<int>& route, const vector<vector<int>>& points)
    {
        r = points[route[0] - 1][0];
        c = points[route[0] - 1][1];
        
        for (int i = 1; i < route.size(); i++)
        {
            Dest.push(route[i] - 1);
        }
    }
    
    string GetHashLocation() const { return to_string(r) + ',' + to_string(c); }
    
    void Tick(const vector<vector<int>>& points) 
    {
        if (Dest.empty())
        {
            r = -1; c = -1;
            return;
        }
        
        int DestNode = Dest.front();
        int DestR = points[DestNode][0], DestC = points[DestNode][1];
        if (r != DestR)
        {
            r > DestR ? r-- : r++;
        }
        else
        {
            c > DestC ? c-- : c++;
        }
        
        if (r == DestR && c == DestC)
        {
            Dest.pop();
        }
    }
    
    bool IsAway()
    {
        return r == -1 && c == -1 ? true : false;
    }
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<Robot> Robots;
    Robots.reserve(routes.size());
    for (const vector<int>& route : routes)
    {
        Robots.emplace_back(Robot(route, points));
    }
    
    int answer = 0;
    unordered_map<string, int> um;
    for (Robot& EachRobot : Robots)
    {
        um[EachRobot.GetHashLocation()]++;
    }

    for (auto it : um)
    {
        if (it.second > 1)
        {
            answer++;
        }
    }
    
    while (1)
    {
        bool bAllOut = true;
        um.clear();
        for (Robot& EachRobot : Robots)
        {
            EachRobot.Tick(points);
            if (!EachRobot.IsAway())
            {
                bAllOut = false;
                um[EachRobot.GetHashLocation()]++;
            }
        }
        
        if (bAllOut)
        {
            break;
        }
        
        for (auto it : um)
        {
            if (it.second > 1)
            {
                answer++;
            }
        }
    }
    
    return answer;
}