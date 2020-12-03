#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    // 낮은 값이 우선순위

    for (auto i : scoville)
        pq.push(i);

    while (1)
    {
        int first = pq.top();
        pq.pop();
        if (pq.empty() && first < K)
        {
            answer = -1;
            break;
        }
        int second = pq.top();
        pq.pop();

        if (first < K)
        {
            pq.push(first + second * 2);
            answer++;
        }
        else
            break;
    }

    return answer;