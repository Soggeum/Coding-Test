#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class V
{
private:
    string parent;
    int money;

public:
    V() : parent(), money(0) {}
    V(string parent) : parent(parent), money(0) {}
    void plusMoney(int amount)
    {
        money += amount;
    }

    const string& getParent() const { return parent; }
    const int& getMoney() const { return money; }
};

class Tree
{
private:
    unordered_map<string, V> nodes;

public:
    Tree(const vector<string>& enroll, const vector<string>& referral, const vector<string>& seller, const vector<int>& amount)
    {
        for (int i = 0; i < enroll.size(); i++) {
            nodes[enroll[i]] = V(referral[i]);
        }

        
        
    }

    void moneyDistribution(const vector<string>& seller, const vector<int>& amount)
    {
        unordered_map<string, int> paper;
        for (int i = 0; i < seller.size(); i++) {
            //paper[seller[i]] += amount[i] * 100;
            distribute({ seller[i], amount[i] * 100 });
        }

        /*for (const auto& target : paper)
            distribute(target);*/
    }
    
    void distribute(pair<string, int> target)
    {
        const string& name = target.first;
        const int amount = target.second;

        if (name == "-") {
            nodes[name].plusMoney(amount);
            return;
        }

        int pay = amount / 10;
        int mine = amount - pay;

        nodes[name].plusMoney(mine);
        if (pay == 0)
            return;
        distribute({ nodes[name].getParent(), pay });

    }

    vector<int> vectorReturn(const vector<string>& enroll)
    {
        vector<int> answer;
        for (const auto& target : enroll) {
            answer.push_back(nodes[target].getMoney());
        }
        
        
        return answer;
    }
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    Tree tree(enroll, referral, seller, amount);
    tree.moneyDistribution(seller, amount);

    return tree.vectorReturn(enroll);
}