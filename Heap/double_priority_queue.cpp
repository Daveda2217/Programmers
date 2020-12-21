/*
https://programmers.co.kr/learn/courses/30/lessons/42628
문제 : 이중우선순위큐
*/

#include <string>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer(2);

    int cnt = 0;

    priority_queue<int> pq_des;
    priority_queue<int, vector<int>, greater<int>> pq_acs;

    for (string op : operations)
    {
        if (!cnt)
        {
            while (!pq_des.empty())
                pq_des.pop();
            while (!pq_acs.empty())
                pq_acs.pop();
        }

        if (op[0] == 'I')
        {
            pq_des.push(stoi(op.substr(2)));
            pq_acs.push(stoi(op.substr(2)));
            cnt++;
        }
        else
        {
            if (!cnt)
                continue;

            if (op[2] == '1')
            {
                pq_des.pop();
                cnt--;
            }
            else
            {
                pq_acs.pop();
                cnt--;
            }
        }
    }

    if (cnt)
    {
        answer[0] = pq_des.top();
        answer[1] = pq_acs.top();
    }

    return answer;
}

/*
어떤 지식을 획득했나요?
1) vector<int> answer(2); // 2로 할당하면 0으로 초기화도 동시에 된다!
2) string to int -> stoi
3) sub string -> substr(#) // 시작점 = # 부터의 substring

*/