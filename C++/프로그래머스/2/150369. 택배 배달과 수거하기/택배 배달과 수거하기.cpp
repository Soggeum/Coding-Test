#include <string>
#include <vector>
#include <stack>

using namespace std;

struct D
{
    int Dist;
    int Delivery;    
};
struct P
{
    int Dist;
    int PickUp;    
};

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    stack<D> DTable;
    stack<P> PTable;
    for (int i = 0; i < deliveries.size();i++)
    {
        if (deliveries[i] > 0)
            DTable.push({i + 1, deliveries[i]});
        if (pickups[i] > 0)
            PTable.push({i + 1 , pickups[i]});
    }
    
    long long answer = 0;
    int Truck;
    while (DTable.size() > 0 || PTable.size() > 0)
    {
        int Departure = (DTable.size() == 0) ? 0: DTable.top().Dist;
        int Arrival = (PTable.size() == 0) ? 0: PTable.top().Dist;
        answer += max(Departure, Arrival) * 2;
        
        Truck = cap;
        while (Truck > 0 && DTable.size() > 0)
        {
            int& box = DTable.top().Delivery;
            if (Truck >= box)
            {
                Truck -= box;
                DTable.pop();
            }
            else
            {
                box -= Truck;
                Truck = 0;
            }
        }
        
        Truck = cap;
        while (Truck > 0 && PTable.size() > 0)
        {
            int& box = PTable.top().PickUp;
            if (Truck >= box)
            {
                Truck -= box;
                PTable.pop();
            }
            else
            {
                box -= Truck;
                Truck = 0;
            }
        }
    }
    return answer;
}