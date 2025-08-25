#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int wallet_w = 0, wallet_h = 0;
    int card_w, card_h;
    for (vector<int> card : sizes) {
        card_w = (card[0] < card[1]) ? card[1]: card[0];
        card_h = (card[0] > card[1]) ? card[1]: card[0];
        if (wallet_w < card_w)
            wallet_w = card_w;
        if (wallet_h < card_h)
            wallet_h = card_h;
    }
    return wallet_w * wallet_h;
}