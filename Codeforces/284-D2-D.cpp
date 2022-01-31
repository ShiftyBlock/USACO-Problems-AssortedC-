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
long dp[2][200001];
set<pii> visited;
int N; v<int> arr;
long recurse(int k, int i){
    if(i<0 || i>=N) return 0;
    if(dp[k][i]!=0) return dp[k][i];
    visited.emplace(make_pair(k, i));
    long sum = arr[i];
    if(k%2==0){
        if(visited.find(make_pair((k+1)%2, i+arr[i])) !=visited.end()){
            return -1;
        }
        long temp = recurse((k+1)%2, i+arr[i]);
        if(temp==-1){
            sum= -1;
        }
        else sum+=temp;
    }
    if(k%2==1){
        if(visited.find(make_pair((k+1)%2, i-arr[i])) !=visited.end()){
            return -1;
        }
        long temp  =-1;
        if(i-arr[i] != 0) {
            temp = recurse((k+1)%2, i-arr[i]);
        }
        if(temp==-1){
            sum= -1;
        }
        else sum+=temp;
    }
    dp[k][i] = sum;
    return sum;
}
int main() {
    setIO("", 0);
    cin>>N;
    arr.push_back(1);
    for(int i=0; i<N-1; i++){
        int num; cin>>num; arr.push_back(num);
    }
    for(int i=1; i<N; i++){
        arr[0] = i;
        recurse(0, 0);
        visited.clear();
        cout<<dp[0][0]<<endl;
        dp[0][0] = 0;
    }


    return 0;
}

