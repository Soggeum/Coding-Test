#include <string>
#include <vector>

using namespace std;

bool Close(const vector<string>& place, int i, int j) {
    vector<int> vdx = {-1, 0, 1, 0};
    vector<int> vdy = {0, -1, 0, 1};
    
    for (int k = 0; k < vdx.size(); k++) {
        int dx = vdx[k], dy = vdy[k];
        if ((j + dx >= 0 && j + dx < place[i].size()) && (i + dy >= 0 && i + dy < place.size()))
        {
            if (place[i + dy][j + dx] == 'P')
                return true;
        }
    }
    
    for (int k = 0; k < vdx.size(); k++) {
        int dx = vdx[k], dy = vdy[k];
        if ((j + dx +dx >= 0 && j + dx + dx < place[i].size()) && (i + dy +dy >= 0 && i + dy + dy < place.size()))
        {
            if (place[i + dy +dy][j + dx + dx] == 'P' && place[i + dy][j + dx] != 'X')
                return true;
        }
    }
    
    vdx = {-1, 1, -1, 1};
    vdy = {-1, -1, 1, 1};
    for (int k = 0; k < vdx.size(); k++) {
        int dx = vdx[k], dy = vdy[k];
        if ((j + dx >= 0 && j + dx < place[i].size()) && (i + dy >= 0 && i + dy < place.size()))
        {
            if (place[i + dy][j + dx] == 'P') {
                if (place[i+dy][j] != 'X' || place[i][j + dx] != 'X')
                    return true;
            }
        }
    }
            
    return false;        
}

int Check(const vector<string>& place) {
    for (int i = 0; i < place.size(); i++) {
        for (int j = 0; j < place[0].size(); j++) {
            if (place[i][j] == 'P') {
                if (Close(place, i, j)) {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        answer.push_back(Check(places[i]));        
    }
    return answer;
}