/*
https://programmers.co.kr/learn/courses/30/lessons/42746
문제 : 가장 큰 수
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> tmp;

    for (auto num : numbers)
        tmp.push_back(to_string(num));

    sort(tmp.begin(), tmp.end(), cmp);

    if (tmp.at(0) == "0")
        return "0";

    for (auto num : tmp)
        answer += num;
    return answer;
}

/*
어떤 지식을 획득했나요?
1) bool cmp 참고
2) 특별한 알고리즘은 아니지만 구현에 있어서 부족함을 느낀 문제였다.
3) numbers가 전부 0일때 예외 케이스에 대해서도 짚고 넘어가야 한다.
*/