#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int i = 0;
    string screen(name.size(), 'A');

    while (1)
    {
        screen[i] = name[i];
        name[i] - 'A' < 'Z' - name[i] + 1 ? answer += name[i] - 'A' : answer += 'Z' - name[i] + 1;

        if (screen == name)
            break;

        for (int move = 1; move < name.size(); move++)
        {
            if (name[(i + move) % name.size()] != screen[(i + move) % name.size()])
            {
                i = (i + move) % name.size();
                answer += move;
                break;
            }
            else if (name[(i + name.size() - move) % name.size()] != screen[(i + name.size() - move) % name.size()])
            {
                i = (i + name.size() - move) % name.size();
                answer += move;
                break;
            }
        }
    }
    return answer;
}

// ABAAAAAAABA 이런 테스트케이스를 생각 못했던 문제
// 이 문제 역시 구현문제..