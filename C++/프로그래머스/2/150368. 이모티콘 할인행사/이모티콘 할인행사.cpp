#include <string>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>& users, 
         const vector<int>& emoticons,
         vector<int>& Sale,
         int idx,
         int& Join,
         int& Money)
{
    if (idx == emoticons.size())
    {
        int NewJoin = 0, NewMoney = 0;
        for (const vector<int>& user : users)
        {
            int ThresholdSale = user[0], ThresholdPay = user[1];
            int Pay = 0;
            for (int i = 0; i < emoticons.size(); i++) 
            {
                if (ThresholdSale <= Sale[i])
                {
                    Pay += emoticons[i] * (100 - Sale[i]) / 100;
                }
            }
            if (Pay >= ThresholdPay)
            {
                NewJoin++;
            }
            else
            {
                NewMoney += Pay;
            }
        }
        
        
        if (NewJoin > Join) 
        {
            Join = NewJoin;
            Money = NewMoney;
        }
        else if (NewJoin == Join && NewMoney > Money) Money = NewMoney;
        return;
    }
    
    for (int discount = 10; discount <= 40; discount += 10)
    {
        Sale[idx] = discount;
        DFS(users, emoticons, Sale, idx + 1, Join, Money);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int Join = 0, Money = 0;
    vector<int> Sale(emoticons.size());
    DFS(users, emoticons, Sale, 0, Join, Money);
    
    return {Join, Money};
}