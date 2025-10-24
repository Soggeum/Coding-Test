#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    int temp;
    unordered_set<int> Sanguen;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        Sanguen.insert(temp);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        if (Sanguen.find(temp) != Sanguen.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}