#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum {}, hashard{x};
    while (hashard) {
        sum += (hashard % 10);
        hashard /= 10;
    }
    

    return !(x % sum);
}