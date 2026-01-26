#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

bool CanChange(const string& a, const string& b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
        }
    }
    
    if (cnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    priority_queue<
        pair<int, string>, 
        vector<pair<int, string>>, 
        std::greater<pair<int, string>>> pq;
      
    vector<int> DistTable(words.size(), numeric_limits<int>::max());
    pq.push({0, begin});  
    
    int cnt;
    string cur;
    while(!pq.empty())
    {
        cnt = pq.top().first;
        cur = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < words.size(); i++)
        {
            if (CanChange(cur, words[i]) && DistTable[i] > cnt + 1)
            {
                pq.push({cnt + 1, words[i]});
                DistTable[i] = cnt + 1;
            }
        }
    }
    
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return 0;
    int idx = it - words.begin();
    if (DistTable[idx] == numeric_limits<int>::max()) return 0;
    else return DistTable[idx];
}