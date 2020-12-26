/*
https://programmers.co.kr/learn/courses/30/lessons/42839
문제 : 소수찾기
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n)
{
    bool isPrime = true;

    if (n == 0 || n == 1)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

int solution(string numbers)
{
    int answer = 0;

    vector<int> v;
    for (int i = 0; i < numbers.size(); i++)
    {
        v.push_back(numbers[i] - '0');
    }

    sort(v.begin(), v.end());

    vector<int> num;

    do
    {
        for (int i = 1; i <= v.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < i; j++)
            {
                temp = temp * 10 + v[j];
                num.push_back(temp);
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (int i = 0; i < num.size(); i++)
    {
        if (is_prime(num[i]))
            answer++;
    }

    return answer;
}

/*
어떤 지식을 획득했나요?
1) is_prime 함수 구현
2) next_permutation 사용법
3) vector안에서 중복된 수 지우기
*/