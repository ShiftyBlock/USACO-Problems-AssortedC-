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
int K; string s;
long dp[(int) 1e6];
void update(int cur, char c){
    if(c=='0'){
        dp[cur] =  dp[2*cur+2];
    }
    if(c=='1'){
        dp[cur] =  dp[2*cur+1];
    }
    if(c=='?'){
        dp[cur] = dp[2*cur+1]  + dp[2*cur+2];
    }
    s[cur] = c;
}
int main() {
    setIO("", 0);
    cin>>K;
     cin>>s;
     int Q; cin>>Q;
    reverse(s.begin(), s.end());
    for(int i=s.length(); i< s.length() + (1<<K); i++){
        dp[i] = 1;
    }
    int N = 1<<K;
    for(int i=N-1; i>=0; i--){
        update(i, s[i]);
    }
   // cout<<dp[0]<<endl;
//heavy inspiration from bucketpotato
     while(Q-->0){
         int idx; cin>>idx;
         char c; cin>>c;
         int i= s.length()-idx;
         update(i, c);
         i--; i/=2;
         while(i>0){
             update(i, s[i]);
             i--; i/=2;
         }
         update(0, s[0]);
         cout<<dp[0]<<endl;
     }

    //2*i, 2*i+1

    return 0;
}

