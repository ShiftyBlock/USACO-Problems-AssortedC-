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
//idea
//changes=K
//given a current point, and C(changes) moves, find the max number of As
//the reason why we care about As is because
// lexographic puts immediate priority on the current letter over later ones
// Afterwards, for all points that we end up with, that have max number of As
// add them to a queue
// changes = changes - maxAs
//repeat until changes ==0
// when changes is done
// go into queue
// fine lexographically smallest string out of the remaining possible paths
char matrix[2001][2001];
int dp[2001][2001];
int temp[2001][2001];
int N, K;
bool valid (int a, int b){
    return a>=0 && a<N && b>=0 && b<N;
}
//dp[i][j] = min number of non-A characters
int main() {
    setIO("", 0);
    cin>>N>>K;
    for(int i=0; i<N; i++){
        string csc; cin>>csc;
        for(int j=0; j<N; j++){
            matrix[i][j]= csc[j];
            if(matrix[i][j]!='a'){
                dp[i][j] = 1;
            }
        }
    }
    int moves=0;
    int curK=min(K, 2*N-1);
    int prevA=0;
    //find max A segments
    //replaced this loop with a dp
    for(int i=1; i<N; i++){
        dp[i][0]+= dp[i-1][0];
    }
    for(int j=1; j<N; j++){
        dp[0][j]+= dp[0][j-1];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
        }
    }
    int maxA=0;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dp[i][j]<=K){
                if(maxA<i+j+1){
                    maxA= i+j+1;
                }
            }
        }
    }
    queue<pii> q;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dp[i][j]<=K){
                if(maxA== i+j+1){
                    q.emplace(i,j);
                }
            }
        }
    }
    //to greedily take letters until we're done
    //we first make a character dp thing
    // store a minimum character that we see next
    // then whenever we update c
    // we add it to a vector (kind of like the thing above)
    // then finally after each iteration of using this move
    // we go through our vector, and only add chars that are equal to min char
    // then we add this min char to our answer
    string ans = "";
    for(int i=0; i<maxA; i++){
        ans+='a';
    }
    if(maxA==0){
        q.emplace(0,0);
        ans+=matrix[0][0];
    }
    while (true) {
        if(q.size()==0) break;
        set<pii> process;
        int mi = 1<<30;
        while(q.size()>0){
            pii cur = q.front(); q.pop();
            int a = cur.first;
            int b = cur.second;
            if (valid(a + 1, b)) {
                if(matrix[a+1][b]<= mi) {
                    mi = matrix[a+1][b];
                    process.emplace(a+1, b);
                }
            }
            if (valid(a, b + 1)) {
                if(matrix[a][b+1]<=mi){
                    mi = matrix[a][b+1];
                    process.emplace(a,b+1);
                }
            }
        }
        for(pii curp: process){
            if(matrix[curp.first][curp.second]== mi){
                q.emplace(curp.first, curp.second);
            }
        }
        if(mi!=1<<30){
            ans+=(char) mi;
        }
    }
    cout<<ans<<endl;






    return 0;
}

