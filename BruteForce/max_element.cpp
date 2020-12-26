/*
https://programmers.co.kr/learn/courses/30/lessons/42840
문제 : 모의고사
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> cnt(3);
    vector<string> v;

    v.push_back("12345");
    v.push_back("21232425");
    v.push_back("3311224455");

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == (v[0][i % 5] - '0'))
        {
            cnt[0]++;
        }
        if (answers[i] == (v[1][i % 8] - '0'))
        {
            cnt[1]++;
        }
        if (answers[i] == (v[2][i % 10] - '0'))
        {
            cnt[2]++;
        }
    }

    int high = 0;
    for (int i = 0; i < 3; i++)
    {
        high = max(high, cnt[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] == high)
            answer.push_back(i + 1);
    }
    return answer;
}

// int high = *max_element(cnt.begin(),cnt.end());

/*
어떤 지식을 획득했나요?
1) vector안에서 max값을 얻고 싶다면 max_element함수를 이용하자!
*/