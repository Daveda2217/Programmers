/*
queue를 이용한 정직한 풀이!!
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int ac = 0; // accrossed truck
    int sec = 0;
    int on_bridge = 0;
    int wt = 0; // waiting truck

    queue<int> bridge;

    while (ac != truck_weights.size())
    {
        // 다리를 건넌 차량의 수와 총 트럭의 수와 같을 때 까지 반복한다.
        if (!bridge.empty() && (sec - bridge.front()) == bridge_length)
        {
            // 다리 위에 트럭이 있고 총 시간에서 트럭이 다리에 진입했을 때 시간의 차가 다리의 길이라면
            on_bridge -= truck_weights[ac];
            // 다리에서 빠져나간다.
            bridge.pop();
            ac++;
            // 다리를 지나간 트럭의 수 ++
        }
        if (wt != truck_weights.size() && (on_bridge + truck_weights[wt]) <= weight)
        {
            // 대기 차량의 수와 총 트럭의 수가 같지않고 다리에 올릴 수 있다면
            on_bridge += truck_weights[wt];
            // 다리에 올려준다.
            bridge.push(sec);
            // 다리에 올라간 시간을 큐에 넣어준다.
            wt++;
            // 다음 차량 인덱스
        }
        sec++;
        // 시간은 매번 증가한다.
    }

    answer = sec;
    return answer;
}

/*
vector pair를 이용한 풀이
*/
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int Time = 0;
    int on_bridge_weight = 0;
    // 다리 위에 있는 트럭의 무게
    vector<pair<int, int>> v;

    while (1)
    {
        int waiting_truck = truck_weights[0];
        // 대기하고 있는 트럭의 무게
        if (!truck_weights.empty() && (on_bridge_weight + waiting_truck) <= weight)
        {
            // 대기하고 있는 트럭이 있고 다리에 올릴 수 있다면
            v.push_back(make_pair(waiting_truck, 0));
            // (무게, 시간)
            truck_weights.erase(truck_weights.begin());
            // 맨 처음 대기하고 있는 트럭은 없애준다.
            on_bridge_weight += waiting_truck;
        }
        for (int i = 0; i < v.size(); i++)
        {
            v[i].second++;
            // 다리 위에 있는 모든 트럭에 대해 시간을 추가해준다.
        }
        if (v[0].second == bridge_length)
        {
            // 첫번째로 다리 위에 있는 트럭의 시간과 다리의 길이가 같다면
            on_bridge_weight -= v[0].first;
            v.erase(v.begin());
            // 다리에서 제거한다.
        }
        Time++;
        if (truck_weights.size() == 0 && v.empty())
            break;
        // 대기하고 있는 트럭도 없고 다리 위에도 트럭이 없다면 끝낸다.
    }
    return ++Time;
    // 다리를 완전히 지나야하므로 1초의 시간을 더한 값을 return해준다.
}