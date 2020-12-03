#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int size = jobs.size();
    int i = 0, time = 0;
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    while (i < size || !pq.empty())
    {
        if (i < size && time >= jobs[i][0])
        { // 현재 시간내에 작업 요청이 있다면 큐에 넣어준다.
            pq.push(jobs[i++]);
            // 똑같은 시간에 요청이 있을 수 있기에 continue
            continue;
        }
        if (!pq.empty())
        {
            // 작업이 끝난 시간을 계산해준다.
            time += pq.top()[1];
            // 요청시간부터 끝날 때 까지의 시간
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
        {
            // 요청된 시간으로 jump
            time = jobs[i][0];
        }
    }

    return answer / size;
}

/*
priority_queue의 사용자 지정 sorting 함수 생성 방법 
이차원 벡터도 sort로 정렬 가능!
*/