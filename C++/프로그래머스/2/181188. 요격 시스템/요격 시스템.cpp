#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
    {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), comp);

    vector<vector<int>> Missile;
    Missile.push_back(targets[0]);
    int MissileStart, MissileEnd, TargetStart, TargetEnd;
    for (int i = 1; i < targets.size(); i++)
    {
        MissileStart= Missile.back()[0];
        MissileEnd= Missile.back()[1];
        TargetStart = targets[i][0];
        TargetEnd = targets[i][1];
        
        if (MissileEnd > TargetStart)
        {
            Missile.back()[0] = TargetStart;
            if (MissileEnd > TargetEnd)
            {
                Missile.back()[1] = TargetEnd;
            }
        }
        else
        {
            Missile.push_back(targets[i]);
        }
    }
    
    
    
    return Missile.size();
}