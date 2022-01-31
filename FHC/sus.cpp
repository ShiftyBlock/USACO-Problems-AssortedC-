#include "bits/stdc++.h"

using namespace std;

int main()
{
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> line;
    for (int i = 0; i < n; i++)
    {
        int cow;
        cin >> cow;
        line.push_back(cow);
    }
    vector<int> sorted_line = line;
    sort(sorted_line.begin(), sorted_line.end());
    int start = -1;
    int end = -1;
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (sorted_line[i] != line[i])
        {
            start = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (sorted_line[i] != line[i])
        {
            end = i;
            break;
        }
    }
    end--;
    //cout << start << " " << end << endl;
    for (int i = 0; i < n; i++)
    {
        if (start <= i && i <= end)
        {
            ans.insert(line[i]);
        }
    }
    cout << ans.size() << endl;
}