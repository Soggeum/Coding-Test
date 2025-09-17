#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int width = ((brown - 4) + sqrt(pow(brown - 4, 2) - 16*yellow)) / 4;
    int height = yellow / width;
                 
    return {width + 2, height + 2};
}