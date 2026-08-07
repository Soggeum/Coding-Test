#include <string>
#include <vector>
#include <sstream>

using namespace std;

// c할 때 아래 행 선택. 없다면 윗 행 선택
// z는 복구만 하면 된다. 선택된 행 변화 없어야함
// 양방향 리스트 벡터
// 이전/ 다음 없으면 -1로
// 삭제할 때 앞/뒤 연결(없으면 안 하기). 삭제한거 벡터에 넣기(인덱스만). k선택 잘
// z하면 벡터에서 빼고 연결(없으면 안 하기)
// 다 하고, 삭제 백터에 이쓴ㄴ것만 answer수정

struct Node
{
    int Prev, Next;    
};

string solution(int n, int k, vector<string> cmd) {
    vector<Node> Table(n);
    for (int i = 0; i < n; i++)
    {
        Table[i].Prev = i - 1;
        Table[i].Next = i + 1;
    }
    Table[0].Prev = -1;
    Table[n - 1].Next = -1;
    
    vector<int> Del;
    for (const string& c : cmd)
    {
        stringstream ss(c);
        string com;
        ss >> com;
        if (com == "U")
        {
            int X;
            ss >> X;
            while (X)
            {
                k = Table[k].Prev;
                X--;
            }
        }
        else if (com == "D")
        {
            int X;
            ss >> X;
            while (X)
            {
                k = Table[k].Next;
                X--;
            }
        }
        else if (com == "C")
        {
            Del.push_back(k);
            int Prev = Table[k].Prev, Next = Table[k].Next;
            if (Prev >= 0)
            {
                Table[Prev].Next = Next;
            }
            if (Next != -1)
            {
                Table[Next].Prev = Prev;                
            }
            k = (Next == -1 ? Prev : Next);
        }
        else
        {
            int d = Del.back();
            Del.pop_back();
            
            int Prev = Table[d].Prev, Next = Table[d].Next;
            if (Prev != -1)
            {
                Table[Prev].Next = d;
            }
            if (Next != -1)
            {
                Table[Next].Prev = d;
            }
        }
    }
    
    string answer(n, 'O');
    for (int x : Del)
    {
        answer[x] = 'X';
    }
    return answer;
}