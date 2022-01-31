/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

long MOD = 1e9+7;

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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, L, R; cin>>N>>L>>R;
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        long sum = 0;
        for(int i=0; i<N; i++){
            auto low = lower_bound(arr.begin(), arr.end(), L-arr[i]) - arr.begin();
            auto high = upper_bound(arr.begin(), arr.end(), R- arr[i]) - arr.begin();
            if(i>=low && i+1<=high) high--;
            sum+=high-low;
        }
        cout<<sum/2<<endl;
    }
    return 0;
}

