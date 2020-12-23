/*
https://programmers.co.kr/learn/courses/30/lessons/42747
문제 : H Index
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    int low = 0;
    int high = citations[0];

    for (int h = low; h <= high; h++)
    {
        int over = 0;
        int j;
        for (j = 0; j < citations.size(); j++)
        {
            if (h <= citations[j])
                over++;
            else
                break;
        }
        if (over >= h)
        {
            answer = h;
        }
    }
    return answer;
}

int another_solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations.size() - i <= citations[i])
        {
            answer = citations.size() - i;
            break;
        }
    }
    return answer;
}
/*
어떤 지식을 획득했나요?
1) sort 내림차순 == greater<int>()
2) 개인적으로 매우 별로인 문제였다.
3) 문제 답에 대한 의견이 많은 것으로 보아 문제 오류가 있을 가능성도 커보인다.
*/