#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> um;

    for (int i = 0; i < phone_book.size(); i++)
    {
        um[phone_book[i]] = 1; // mapping
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            phone_number += phone_book[i][j];
            if (um[phone_number] && phone_number != phone_book[i]) // hash값이 존재하고 자기 자신 값이 아니라면
            {
                return false;
            }
        }
    }
    return true;
}