#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    unordered_map<string, int> um;
    for (int i = 0; i < clothes.size(); i++)
    {
        um[clothes[i][1]]++; // mapping
    }
    for (auto i = um.begin(); i != um.end(); i++) // 이 방식 기억하기!! map은 begin, end로 순회된다.
    {
        answer *= i->second + 1; // 착용 x 경우의 수 포함해서 구하기
    }

    return answer - 1; // 전부 착용 x 경우의 수 1 빼기
}