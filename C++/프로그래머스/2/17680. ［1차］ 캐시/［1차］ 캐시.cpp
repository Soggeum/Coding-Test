#include <string>
#include <vector>
#include <list>

using namespace std;

void lower(string& city)
{
    for (char& c : city)
    {
        c = tolower(c);
    }
}

int solution(int cacheSize, vector<string> cities) {
    list<string> Cache;    
    int answer = 0;
    for (string city : cities)
    {
        lower(city);
        
        auto it = Cache.begin();
        for (; it != Cache.end(); it++)
        {
            if (*it == city)
            {
                answer++;
                Cache.push_back(*it);
                Cache.erase(it);
                break;
            }
        }
        if (it == Cache.end())
        {
            answer += 5;
            Cache.push_back(city);
            if (Cache.size() > cacheSize)
            {
                Cache.pop_front();   
            }
        }
    }
    
    return answer;
}