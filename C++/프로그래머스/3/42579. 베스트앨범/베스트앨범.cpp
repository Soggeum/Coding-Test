#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, int>&a, const pair<int, int>&b)
    {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
        
    }
};

bool vcompare(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> GenreTable;
    unordered_map<string, 
                  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>> PlayTable;
    for (int i = 0; i < genres.size(); i++)
    {
        string g = genres[i];
        GenreTable[g] += plays[i];
        PlayTable[g].push({plays[i], i});
    }
    
    vector<pair<string, int>> v(GenreTable.begin(), GenreTable.end());
    sort(v.begin(), v.end(), vcompare);
    
    vector<int> answer;
    for (const auto& [g, c] : v)
    {
        for (int i = 0; i < 2; i++)
        {
            if (PlayTable[g].empty()) break;
            answer.push_back(PlayTable[g].top().second);
            PlayTable[g].pop();
        }
    }
    
    return answer;
}