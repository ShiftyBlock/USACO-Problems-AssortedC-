#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > cows;
    pair<int, int> cow;
    for (int i = 0; i < n; i++)
    {
        int p, s;
        cin >> p >> s;
        cows.push_back(make_pair(p, s));
    }
    sort(cows.begin(), cows.end());
    for (auto i : cows)
    {
        cout << i.first << " " << i.second << endl;
    }
    int max_r = 10000000;
    for (int i = 0; i < n; i++)
    {
        // index isnt 0 and is not sick
        if (i != 0 && cows[i].second == 0)
        {
            if (cows[i].first - cows[i - 1].first < max_r)
            {
                max_r = cows[i].first - cows[i - 1].first;
            }
            if (cows[i + 1].first - cows[i].first < max_r)
            {
                max_r = cows[i].first - cows[i - 1].first;
            }
        }
        //index is > 0
        else if (cows[i].second == 0)
        {
            if (cows[i + 1].first - cows[i].first < max_r)
            {
                max_r = cows[i].first - cows[i - 1].first;
            }
        }
    }
    cout << max_r << endl;
}