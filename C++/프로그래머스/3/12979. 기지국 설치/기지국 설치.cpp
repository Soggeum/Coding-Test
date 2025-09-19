#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int unWifi = 1;
    float needed;
    for (int i = 0; i < stations.size(); i++) {
        needed = (float)((stations[i] - w - 1) - unWifi + 1) / (2 * w + 1);
        answer += max((float)0.0, ceil(needed));
        unWifi = stations[i] + w + 1;
    }
    if (unWifi <= n) {
        needed = (float)(n - unWifi + 1) / (2 * w + 1);
        answer += ceil(needed);
    }
    
    return answer;
}