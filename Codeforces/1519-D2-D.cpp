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
long dp[5001][5001];
int N;
long prefix[5001];
long suffix[5001];
bool valid(int a, int b){
    return a>=0 && b>=0 && a<N && b<N;
}
int main() {
    setIO("", 0);
    cin>>N;
    v<long> arr1, arr2;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr1.push_back(num);
    }
    for(int i=0; i<N; i++){
        int num; cin>>num; arr2.push_back(num);
    }
    //flip starting from 1 segment
    for(int i=0; i<N; i++){
        dp[i][i] = arr1[i] * arr2[i];
        int low = i;
        int high = i;
        while(valid(low-1, high+1)){
            low--; high++;
            dp[low][high] = dp[low+1][high-1] + arr1[low] * arr2[high] + arr1[high]* arr2[ low];
        }
    }
    //flip starting from 2
    for(int i=0; i<N-1; i++){
        dp[i][i+1]  = arr1[i]*arr2[i+1] + arr1[i+1] * arr2[i];
        int low = i;
        int high = i+1;
        while(valid(low-1, high+1)){
            low--; high++;
            dp[low][high] = dp[low+1][high-1] + arr1[low] * arr2[high] + arr1[high]* arr2[ low];
        }
    }
    //find best product prefix and suffix
    for(int i=0; i<N; i++){
        prefix[i] = arr1[i] * arr2[i];
        if(i!=0) prefix[i]+=prefix[i-1];
    }
    for(int i=N-1; i>=0; i--){
        suffix[i] = arr1[i] * arr2[i];
        if(i!=N-1) suffix[i]+=suffix[i+1];
    }
    long ans = prefix[N-1];
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            long psum =0;
            if(valid(i-1, 0)){
                psum = prefix[i-1];
            }
            long ssum = 0;
            if(valid(j+1, 0)){
                ssum = suffix[j+1];
            }
            ans = max(ans, dp[i][j] + psum + ssum);
        }
    }
    cout<<ans<<endl;


    return 0;
}

