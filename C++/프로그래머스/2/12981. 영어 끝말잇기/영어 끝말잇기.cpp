#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> Table = {words[0]};
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i][0] != words[i - 1].back() || Table.find(words[i]) != Table.end())
        {
            return {i % n + 1, i / n + 1};
        }
        Table.insert(words[i]);
    }

    return {0, 0};
}