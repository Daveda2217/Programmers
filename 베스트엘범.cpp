#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp1(pair<string, int> &a,
          pair<string, int> &b)
{
    return a.second > b.second;
}

bool cmp2(pair<int, int> &a,
          pair<int, int> &b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> m;
    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i]; // get total of genres
    }

    vector<pair<string, int>> v; // map sort

    for (auto &iter : m)
    {
        v.push_back(iter);
    }

    sort(v.begin(), v.end(), cmp1);

    for (int i = 0; i < v.size(); i++)
    {
        vector<pair<int, int>> tmp;

        for (int j = 0; j < genres.size(); j++)
        {
            if (genres[j] == v[i].first)
            {
                tmp.push_back({plays[j], j}); // push plays, index
            }
        }
        sort(tmp.begin(), tmp.end(), cmp2);

        if (tmp.size() == 1)
        {
            answer.push_back(tmp[0].second);
        }
        else
        {
            answer.push_back(tmp[0].second);
            answer.push_back(tmp[1].second);
        }
    }
    return answer;
}