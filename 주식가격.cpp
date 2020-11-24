#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        int price_down = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] > prices[j])
            {
                // 가격이 떨어졌다면
                price_down++; // 1초간 가격이 떨어지지 않은 것으로 본다.
                break;
            }
            else
            {
                price_down++;
            }
        }
        answer.push_back(price_down);
    }
    answer.push_back(0);

    return answer;
}