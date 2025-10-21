#include <string>
#include <vector>
#include <queue>

using namespace std;

struct BridgeData {
    int BridgeLength;
    int CurrentBridgeWeight;
    int MaxBridgeWeight;    
};

bool IsBridgeEmpty(const struct BridgeData& InBridgeData) {
    return (InBridgeData.CurrentBridgeWeight == 0);
}

bool CanTruckGo(const int TruckWeight, const struct BridgeData& InBridgeData) {
    return (InBridgeData.CurrentBridgeWeight + TruckWeight <= InBridgeData.MaxBridgeWeight);
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    struct BridgeData InBridgeData;
    InBridgeData.BridgeLength = bridge_length;
    InBridgeData.CurrentBridgeWeight = 0;
    InBridgeData.MaxBridgeWeight = weight;
    
    queue<int> TruckIdxOnBridge;
    for (int i = 0; i < bridge_length; i++) {
        TruckIdxOnBridge.push(-1);
    }
    
    int answer = 1, TruckIdx = 0;
    TruckIdxOnBridge.pop();
    TruckIdxOnBridge.push(0);
    InBridgeData.CurrentBridgeWeight += truck_weights[0];
    TruckIdx++;
    
    int OutTruckIdx;
    while (!IsBridgeEmpty(InBridgeData)) {        
        answer++;
        OutTruckIdx = TruckIdxOnBridge.front();
        TruckIdxOnBridge.pop();   
        InBridgeData.CurrentBridgeWeight -= truck_weights[OutTruckIdx];
        
        if ((TruckIdx < truck_weights.size()) && CanTruckGo(truck_weights[TruckIdx], InBridgeData)) {
            TruckIdxOnBridge.push(TruckIdx);
            InBridgeData.CurrentBridgeWeight += truck_weights[TruckIdx];
            TruckIdx++;
        }
        else {
            TruckIdxOnBridge.push(-1);
        }
        
    }
    
    return answer;
}