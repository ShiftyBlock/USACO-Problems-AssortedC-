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
void fake(int N, v<long> arr){
    long bestsum=1e18;
    sort(arr.begin(), arr.end());
    do{
        long temp = 0;
        long mini = 1e18; long maxi=0;
        for(int i=0; i<N; i++){
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
            temp+=maxi-mini;
        }
        bestsum = min(bestsum, temp);
    }
    while(next_permutation(arr.begin(), arr.end()));

    do{
        long temp = 0;
        long mini = 1e18; long maxi=0;
        for(int i=0; i<N; i++){
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
            temp+=maxi-mini;
        }
        if(temp==bestsum){
            cout<<"SUM: "<<bestsum<<" ";
            for(int i=0; i<N; i++){
               cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    while(next_permutation(arr.begin(), arr.end()));
}
long dp[2001][2001];
long big[2001][2001];
long small[2001][2001];
int N;
long recurse(int i, int j){
    if(i==j) return 0;
    if(dp[i][j]!=(long)1e18){
        return dp[i][j];
    }
    long cost1 = recurse(i+1, j);
    long cost2= recurse(i, j-1);
    dp[i][j] = min(cost1, cost2) + big[i][j] - small[i][j];
    return dp[i][j];
}
int main() {
    setIO("", 0);
    cin>>N;
    v<long> arr;
    for(int i=0; i<N; i++){
        long num; cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<N; i++){
        long cm = arr[i];
        for(int j=i; j<N; j++){
            cm = min(cm, arr[j]);
            small[i][j] = cm;
        }
    }
    for(int i=0; i<N; i++){
        long cm = arr[i];
        for(int j=i; j<N; j++){
            cm = max(cm, arr[j]);
            big[i][j] = cm;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            dp[i][j] = 1e18;
        }
    }
    cout<<recurse(0,N-1)<<endl;
    //take extreme elements on range
    /*for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(i>0){
                dp[i-1][j] =min(dp[i][j] + big[i-1][j] - small[i-1][j] , dp[i-1][j] );
            }
            if(j<N){
                dp[i][j+1] = min(dp[i][j] + big[i][j+1] - small[i][j+1] , dp[i][j+1]);
            }
        }
    }*/
    //fake(N, arr);
  //  cout<<dp[0][N-1]<<endl;

    return 0;
}

