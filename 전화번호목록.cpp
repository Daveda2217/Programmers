#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end()); // sort

    for (int i = 0; i < phone_book.size() - 1; i++) // 0 ~ phone_book.size() - 1
    {
        size_t idx = phone_book[i + 1].find(phone_book[i]); // phone_book[i]를 찾기
        if (idx != string::npos && idx == 0)                // 찾았고 찾은 index가 0이라면
        {
            answer = false;
            break;
        }
    }
    return answer;
}