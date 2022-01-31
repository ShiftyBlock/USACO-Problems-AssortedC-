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
//bitmask 10101 = ith bit set = taken that digit already
// j = remainder
// dp[i][j] -> dp[i | 1<<k ](10*j + arr[k])%MOD]
// also cannot start with a mask where the first number is a 0

__int128 dp[1<<18][100];
int main() {
    setIO("", 0);
    long N, M; cin>>N>>M;
    v<int> arr;
    while(N>0){
        arr.push_back(N%10);
        N/=10;
    }

    dp[0][0] = 1;
    for(int mask=0; mask<(1<<arr.size()); mask++){
        bool valid = true;
        for(int i=0; i<arr.size(); i++){
            if(mask==(1<<i) && arr[i]==0) valid=false;
        }
        if(!valid) continue;
        for(int i=0; i<arr.size(); i++){
            for(int m=0; m<M; m++){
                if(!(mask&(1<<i))) dp[mask|(1<<i)][(10*m + arr[i])%M]+=dp[mask][m];
            }
        }
    }
    //rearrange same numbers, so divide by count!
    v<int> count(10);
    for(int x: arr){
        count[x]++;
    }
    __int128 ans = dp[(1<<arr.size()) - 1][0];
    for(int i=0; i<10; i++){
        for(int j=1; j<=count[i];j++){
            ans/=j;
        }
    }
    cout<<(long) ans<<endl;

    return 0;
}

