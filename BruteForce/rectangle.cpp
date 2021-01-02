#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    //     가로 >= 세로
    //     brown + yellow = area
    //     e.g.
    //     12 = 12*1, 6*2, 4*3
    int area = brown + yellow;

    for (int i = 1; i <= area / 2; i++)
    {
        //         1 ~ 6 (time Complexity를 줄이기 위해)
        if (area % i == 0)
        {
            //            1, 2, 3, 4, 6
            //            i -> 세로, area / i -> 가로
            int height = i;
            int width = area / i;
            int temp = 2 * height + 2 * width - 4;

            if (temp == brown)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}

// 비록 매우 간단한 문제였지만
// ps에 자신감을 조금 높여준 문제
// 최근에 코딩을 많이 하다보니 구현력이 좋아진거 같다!
// 2021년 소띠해! 열심히 공부하고 일하자!