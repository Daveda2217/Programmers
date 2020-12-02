#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    int size = priorities.size();
    queue<pair<int, int>> q;

    for (int i = 0; i < size; i++)
    {
        q.push({priorities[i], i});
    }
    sort(priorities.begin(), priorities.end(), cmp);

    while (!q.empty())
    {
        auto curr = q.front();
        bool flag = true;

        for (int i = 0; i < size; i++)
        {
            if (curr.first < priorities[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            answer++;
            priorities.erase(priorities.begin());
            size--;
            if (curr.second == location)
                break;
            q.pop();
        }
        else
        {
            q.push(curr);
            q.pop();
        }
    }
    return answer;
}

/*
vector에 max_element(v.begin(),v.end()) 함수가 있다는 것을 기억하자!
*/