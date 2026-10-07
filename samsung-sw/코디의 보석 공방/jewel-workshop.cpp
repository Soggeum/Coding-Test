#include <iostream>
#include <vector>

using namespace std;

struct Jewel
{
    int w, v;
};

int Sell(int N, vector<Jewel>& Table, vector<int>& WeightTable, int& Cnt)
{
    int idx;
    cin >> idx;
    
    if (idx > N)
    {
        return -1;
    }

    Jewel& jewel = Table[idx];
    if (jewel.w == -1)
    {
        return -1;
    }

    int Res = jewel.v;
    WeightTable[jewel.w]--;
    jewel.w = -1;
    jewel.v = -1;
    Cnt--;
    return Res;
}

int Display(int N, const vector<Jewel>& Table)
{
    // DP
    int W;
    cin >> W;
    vector<int> DP(W + 1, -1);
    DP[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        const Jewel& jewel = Table[i];
        if (jewel.w == -1)
        {
            continue;
        }
        for (int j = W; j >= jewel.w; j--)
        {
            if (DP[j - jewel.w] != -1)
            {
                DP[j] = max(DP[j], DP[j - jewel.w] + jewel.v);
            }                    
        }
    }

    int Res = 0;
    for (int v : DP)
    {
        Res = max(Res, v);
    }
    return Res;
}

int Combination(int N, const vector<int>& WeightTable, int Cnt)
{
    int D;
    cin >> D;
    if (Cnt < 2)
    {
        return 0;
    }

    int Res = 0, Start = 1;
    for (; Start <= 3000; Start++)
    {
        if (WeightTable[Start])
        {
            break;
        }
    }
    
    int TargetCnt = 0;
    for (int i = Start + 1; i <= Start + D; i++)
    {
        if (i <= 3000)
        {
            TargetCnt += WeightTable[i];
        }
    }

    for (; Start <= 3000; Start++)
    {
        if (WeightTable[Start])
        {
            Res += WeightTable[Start] * (WeightTable[Start] - 1) / 2;
        }
        if (TargetCnt)
        {
            Res += WeightTable[Start] * TargetCnt;
        }

        if (Start + 1 <= 3000)
        {
            TargetCnt -= WeightTable[Start + 1];            
        }
        if (Start + 1 + D <= 3000)
        {
            TargetCnt += WeightTable[Start + 1 + D];
        }
    }

    return Res;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, N, Cnt = 0;
    cin >> Q;
    vector<Jewel> Table;
    vector<int> WeightTable(3001);

    for (; Q > 0; Q--)
    {
        int Op;
        cin >> Op;
        if (Op == 1)
        {
            cin >> N;
            Cnt = N;
            Table = vector<Jewel>(N + 1);
            for (int i = 1; i <= N; i++)
            {
                cin >> Table[i].w >> Table[i].v;
                WeightTable[Table[i].w]++;
            }
        }
        else if (Op == 2)
        {
            Jewel jewel;
            cin >> jewel.w >> jewel.v;
            WeightTable[jewel.w]++;
            Table.emplace_back(jewel);
            N++;
            Cnt++;
        }
        else if (Op == 3)
        {
            cout << Sell(N, Table, WeightTable, Cnt) << '\n';
        }
        else if (Op == 4)
        {
            cout << Display(N, Table) << '\n';
        }
        else
        {
            cout << Combination(N, WeightTable, Cnt) << '\n';
        }
    }

    return 0;
}