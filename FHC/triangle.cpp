#include "bits/stdc++.h"

using namespace std;
#define OFFSET 10000
#define MOD (int)(1e9+7)
//adjacency lists
int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    //10000 + 10000 = 20000
    vector<int> xs[10001 + OFFSET];
    vector<int> ys[10001 + OFFSET];
    //added code
    vector<int> xsum[10001 + OFFSET];
    vector<int> ysum[10001 + OFFSET];

    vector< pair<int, int> > points;
    vector<int> x_coords;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        //stores all the points for a same x and a same y
        xs[x + OFFSET].push_back(y + OFFSET);
        ys[y + OFFSET].push_back(x+ OFFSET);
        points.push_back(make_pair(x + OFFSET, y + OFFSET));
    }
    for(int i=0; i<10001 + OFFSET; i++){
        sort(xs[i].begin(), xs[i].end());
        sort(ys[i].begin(), ys[i].end());
    }
    //calculate xsum using the xs values (and they're sorted! surprise!)
    //using 1 for loop
    //repeat process for ysum

    long long ans = 0;
    for (pair<int, int> i : points)
    {
        //lower bound searches an array in O(log N) time
        //it will point to the minimal index that is >= the last thing in the method call (i.second)
        // we know that what we're searching for always exists, so we'll get what we want
        //LB returns an iterator, this is uselss and I don't teach referencing, indexing is cooler
        // so convert to an index (subtract the iterators)
        int xIdx =  lower_bound(xs[i.first].begin(), xs[i.first].end(), i.second) - xs[i.first].begin();
        //go look into xsum
        // we want x_sum = xsum[i.first][xIdx]

        long long x_sum = 0;
        long long y_sum = 0;
        //convert this to O(1) time
        //you will call xsum[i.first][index]
        //how do you find index
        for (int x = 0; x < xs[i.first].size(); x++)
        {
            x_sum += abs(xs[i.first][x] - i.second);
        }
        for (int x = 0; x < ys[i.second].size(); x++)
        {
            y_sum += abs(ys[i.second][x] - i.first);
        }
        ans += (x_sum * y_sum)%MOD;
        ans%=MOD;
    }
    cout << (ans % MOD) << endl;






}