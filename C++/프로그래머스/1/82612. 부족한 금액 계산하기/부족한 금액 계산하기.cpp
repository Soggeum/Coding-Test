using namespace std;

long long solution(int price, int money, int count)
{
    long long pay = 0;
    
    for (int i = 1; i <= count; i++) {
        pay += price * i;
    }

    return (pay <= money) ? 0: (pay - money);
}