#include "bits/stdc++.h"

// Only got 1 test case

using namespace std;

int main()
{
   freopen("reststops.in", "r", stdin);
   // freopen("reststops.out", "w", stdout);
    int l, n, f, b;
    cin >> l >> n >> f >> b;
    vector< pair<long, long> > rest_stops;
    pair<int, int> rest_stop;
    int x, c;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> c;
        rest_stops.push_back(make_pair(c, x));
    }
    sort(rest_stops.begin(), rest_stops.end());
    reverse(rest_stops.begin(), rest_stops.end());
    // for (auto i : rest_stops)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    long distance = 0;
    long total = 0;
    for (pair<long, long> i : rest_stops)
    {
        if (distance < i.second)
        {
            //cout << i.second << " ";
            total += (f - b) * (i.second - distance) * i.first;
            distance = i.second;
        }
    }
    cout << total << endl;
}