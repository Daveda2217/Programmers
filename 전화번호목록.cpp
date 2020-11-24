#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {

        size_t idx = phone_book[i + 1].find(phone_book[i]);
        if (idx != string::npos && idx == 0)
        {
            answer = false;
            break;
        }
    }
    return answer;
}