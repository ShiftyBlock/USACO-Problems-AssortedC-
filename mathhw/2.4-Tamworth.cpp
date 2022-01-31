/*
ID: davidzh8
PROG: ttwo
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
v<int> dx= {-1, 0, 1, 0};
v<int> dy={0, 1, 0, -1};
struct state{
    int i,j,d;
    state(int a, int b, int c){
        i=a; j=b; d=c;
    }
};
int matrix[10][10];
bool valid(int a, int b){
    return a>=0 && a<10 && b>=0 && b<10 && matrix[a][b]!=1;
}

int visited[4][10][10][4][10][10];
int main() {
    setIO("ttwo", 1);
    state COW = {-1, -1, 0};
    state FJ = {-1,-1,0};
    for(int i=0; i<10; i++){
        string s; cin>>s;
        for(int j=0; j<10; j++){
            if(s[j]=='*'){
                matrix[i][j] = 1;
            }
            if(s[j]=='F'){
                FJ.i = i; FJ.j=j;
            }
            if(s[j]=='C'){
                COW.i=i; COW.j=j;
            }
        }
    }
    queue<pair<state,state>> q;
    q.emplace(COW,FJ);
    visited[0][COW.i][COW.j][0][FJ.i][FJ.j] =1;
    int moves = 0;
    while(q.size()>0){
        auto cow = q.front().first;
        auto fj = q.front().second;
        q.pop();
        if(valid(cow.i+dx[cow.d], cow.j+dy[cow.d])){
            cow = state{cow.i+dx[cow.d], cow.j+dy[cow.d], cow.d};
        }
        else{
            cow.d = (cow.d+1)%4;
        }
        if(valid(fj.i+dx[fj.d], fj.j+dy[fj.d])){
            fj = state{fj.i+dx[fj.d], fj.j+dy[fj.d], fj.d};
        }
        else{
            fj.d = (fj.d+1)%4;
        }
        moves++;
        if(cow.i == fj.i && cow.j== fj.j){
            cout<<moves<<endl; break;
        }
        if(visited[cow.d][cow.i][cow.j][fj.d][fj.i][fj.j]==1){
            cout<<0<<endl; break;
        }
        visited[cow.d][cow.i][cow.j][fj.d][fj.i][fj.j]=1;
        q.emplace(cow, fj);
    }
    return 0;
}

