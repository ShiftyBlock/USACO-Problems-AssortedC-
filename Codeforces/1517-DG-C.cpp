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
int N;
int matrix[501][501];
bool valid(int a, int b){
    if(a>=0 && a<N && b>=0 && b<N){
        if(matrix[a][b]==0){
            return true;
        }
        return false;
    }
    return false;
}
void fi(pii start, int val){
    queue<pii> q;
    q.emplace(start);
    int counter=1;
    while(q.size()>0){
        pii cur = q.front(); q.pop();
        if(counter==val){
            continue;
        }
        int cx= cur.first;
        int cy= cur.second;
        //if yu can go down
        if(valid(cx+1, cy)){
            matrix[cx+1][cy]=val;
            q.emplace(make_pair(cx+1,cy));
        }
        //otherwise left is ok too
        else if (valid (cx, cy-1)){
            matrix[cx][cy-1]=val;
            q.emplace(make_pair(cx, cy-1));
        }
        counter++;
    }
}
//idea
//just go down
//and if you can't, go left
//starting from right
int main() {
    setIO("", 0);
   cin>>N;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        matrix[i][i]=num;
    }
    for(int i=N-1; i>=0; i--){
        fi(make_pair(i,i), matrix[i][i]);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j]==0) continue;
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            matrix[i][j] =0;
        }
    }
    return 0;
}

