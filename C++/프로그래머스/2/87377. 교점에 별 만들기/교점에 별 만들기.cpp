#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool IsCross(const long long& A, const long long& B, const long long& C, 
             const long long& D, const long long& E, const long long& F)
{
    if (A * D == B * C) return false;
    if ((B * F - E * D) % (A * D - B * C) == 0 && (E * C - A * F) % (A * D - B * C) == 0) 
        return true;
    return false;
}

vector<string> solution(vector<vector<int>> line) {
    set<pair<long long, long long>> Cross;
    long long A, B, C, D, E, F;
    for (int i = 0; i < line.size(); i++) 
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            A = line[i][0];
            B = line[i][1];
            C = line[j][0];
            D = line[j][1];
            E = line[i][2];
            F = line[j][2];
            
            if (IsCross(A, B, C, D, E, F))
            {
                Cross.insert({(B * F - E * D) / (A * D - B * C), (E * C - A * F) / (A * D - B * C)});
            }
        }
    }
    
    auto it = Cross.begin();
    long long MinX = it->first, MaxX= it->first, MinY = it->second, MaxY = it->second;
    it++;
    long long X, Y;
    for (; it != Cross.end(); it++)
    {
        X = it->first;
        Y = it->second;
        
        MinX = min(MinX, X);
        MaxX = max(MaxX, X);
        MinY = min(MinY, Y);
        MaxY = max(MaxY, Y);
    }
    
    vector<string> answer(MaxY - MinY + 1, string(MaxX - MinX + 1, '.'));
    for (const auto& [X, Y] : Cross)
    {        
        answer[MaxY - Y][X - MinX] = '*';
    }
    return answer;
}