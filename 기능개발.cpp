#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> temp;
    int size = progresses.size();

    for (int i = 0; i < size; i++)
    {
        int days = 0;
        while (progresses[i] < 100)
        {
            progresses[i] += speeds[i]; // 하루에 증가하는 일의 percentage
            days++;                     // 하루 증가
        }
        temp.push_back(days); // 100% 달성하면 days push
    }

    int complete = temp[0]; // 처음으로 완료하는데 걸린 날
    int continuous = 1;     // 연속적으로 배포 가능한 작업 수

    for (int i = 1; i < size; i++)
    {
        if (complete >= temp[i])
        {                 // 처음으로 걸린 날보다 작거나 같을 때
            continuous++; // 연속적으로 배포 가능
        }
        else
        { // 더 오래걸린다면
            answer.push_back(continuous);
            continuous = 1;     // 초기화
            complete = temp[i]; // 초기화
        }
    }
    answer.push_back(continuous);

    return answer;
}