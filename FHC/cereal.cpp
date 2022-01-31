#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<int> cereals(m);
int pref [100000][2];
int ans = 0;
vector<int> res;
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
}
int main()
{
    setIO("cereal", 1);
    cin >> n >> m;
    cereals.resize(m);
    res.resize(n);
    fill(cereals.begin(), cereals.end(), 1e6);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pref[i][0] = a-1;
        pref[i][1] = b-1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        //preferences[i][0] is 1st choice
        //preferences[i][1] is 2nd choice
        //cereals[cur] is cow currently taking the 1st choice cereal of current cow

        int j = i;
        //when look = 0, we will always get our first choice
        //because we have priority
        //bottom to top
        int look = 0;
        while(true){
            int cur = pref[j][look];
            //owner[curCeral] -> cereals[cur]
            if (cereals[cur] == 1e6)
            {
                cereals[cur] = j;
                ans++;
            }
            //check if the owner has less priority than us
            else if (cereals[cur] > j){
                //we look at cereals[cur] cow next
                //his first choice got kicked out so it must be second
                //cereals[cur] is assigned to our current cow
                int next = cereals[cur];
                cereals[cur] = j;
                j = next;
                look = 1;
            }
            else break;
        }
        res[i] = ans;
    }
    for(int x: res){
        cout<<x<<endl;
    }
}