#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    int no_cloth, has_cloth;
    bool is_erased = false;

    for (auto it = lost.begin(); it != lost.end();)
    {
        is_erased = false;
        no_cloth = *it;
        for (auto itt = reserve.begin(); itt != reserve.end(); itt++)
        {
            has_cloth = *itt;
            if (no_cloth == has_cloth)
            {
                it = lost.erase(it);
                reserve.erase(itt);
                is_erased = true;
                break;
            }
        }

        if (!is_erased)
            it++;
    }

    for (auto it = lost.begin(); it != lost.end();)
    {
        is_erased = false;
        no_cloth = *it;
        for (auto itt = reserve.begin(); itt != reserve.end(); itt++)
        {
            has_cloth = *itt;
            if (no_cloth - 1 == has_cloth || no_cloth + 1 == has_cloth)
            {
                it = lost.erase(it);
                reserve.erase(itt);
                is_erased = true;
                break;
            }
        }

        if (!is_erased)
            it++;
    }

    return answer - lost.size();
}

// vector erase에 대해서 완벽히 이해하게 된 문제!
// 처음엔 find를 이용해서 풀었는데 자꾸 틀려서
// naive하게 풀었다.