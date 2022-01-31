#include "bits/stdc++.h"

using namespace std;
int trees[1001];
int main()
{
    //freopen("berries.in", "r", stdin);
    //freopen("berries.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    priority_queue<int> temp_trees;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];

        temp_trees.push(trees[i]);
    }
    int ans = 0;

    int range = temp_trees.top();
    vector<int> poss;
    //alert
    //no basket will ever be greater than X
    for (int x = 1; x <= 1000; x++)
    {
        int temp_ans = 0;
        for (int y = 0; y < k; y++)
        {
            if (temp_trees.top() >= x)
            {
                poss.push_back(x);
                temp_trees.push(temp_trees.top() - x);
                temp_trees.pop();
            }
            else break;
        }
        int possSize = poss.size();
        int remaining = k- possSize;
        while(remaining-->0){
            poss.push_back(temp_trees.top());
            temp_trees.pop();
        }
        sort(poss.rbegin(), poss.rend());
        for(int thing: poss){
            cout<<thing<<" ";
        }
        cout<<endl;
        // take bottom half
        for (int i = k/2; i < poss.size(); i++)
        {
            temp_ans += poss[i];
        }
        poss =vector<int>();
        temp_trees = priority_queue<int> ();
        for (int i = 0; i < n; i++)
        {
            temp_trees.push(trees[i]);
        }
        ans = max(temp_ans, ans);
    }
    cout << ans << endl;
}