#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next_truck = 0;
    int weight_sum = 0;
    queue<int> on_bridge;
    
    for(int i=0; i<bridge_length; i++)
        on_bridge.push(0);
    
    while(!on_bridge.empty()){
        answer++; //초 증가
        weight_sum -= on_bridge.front();        
        on_bridge.pop();
        
        //대기 트럭이 있는 경우
        if(next_truck < truck_weights.size()){
            //다리 위 트럭무게와 다음 트럭무게를 합친결과가 제한무게 보다 작으면
            if(weight_sum + truck_weights[next_truck] <= weight){
                weight_sum += truck_weights[next_truck];
                on_bridge.push(truck_weights[next_truck]);
                next_truck++;
            }
            else
                on_bridge.push(0);
        }
    }
    
    return answer;
}