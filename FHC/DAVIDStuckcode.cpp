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

const int MAXN= 51;
char D[MAXN];
int SX[MAXN]; int SY[MAXN];
int X[MAXN]; int Y[MAXN];
int main() {
    setIO("", 0);
    int N; cin>>N;
    set<int> stuck;
    set<string> visited;
    for(int i=0; i<N; i++){
        cin>> D[i]>> X[i]>>Y[i];
        SX[i]= X[i];
        SY[i]= Y[i];
        string key = to_string(X[i])+" "+to_string(Y[i]);
        visited.insert(key);
    }
    v<int> ans;
    ans.assign(N,0);
    while(true){
        int timeuntilstuck=1<<30;
        for(int i=0; i<N; i++){
            if(stuck.count(i)) continue;
            for(int j=0; j<N; j++){
                if(D[i]=='E'){
                    if(D[j]=='N'){
                        if(X[j]>X[i] && SY[j]<Y[i]){
                            timeuntilstuck = min( X[j]-X[i], timeuntilstuck);
                        }
                    }
                }
                if(D[i]=='N'){
                    if(D[j]=='E'){
                        if(SX[j]<X[i] && Y[j]>Y[i]){
                            timeuntilstuck = min( Y[j]-Y[i], timeuntilstuck);
                        }
                    }
                }
            }
        }
        if(timeuntilstuck==1<<30) break;
        // moving my cows
        for(int i=0; i<N; i++){
            if(stuck.count(i)){
                continue;
            }
            // add distance to answer
            ans[i]+=timeuntilstuck;
            if(D[i]=='E'){
                X[i]+=timeuntilstuck;
            }
            if(D[i]=='N'){
                Y[i]+=timeuntilstuck;
            }
            // if this spot was already visited b4
            string key = to_string(X[i])+" "+to_string(Y[i]);
            if(visited.count(key)){
                stuck.emplace(i);
            }
        }
        for(int i=0; i<N; i++){
            if(stuck.count(i)){
                continue;
            }
            string key = to_string(X[i])+" "+to_string(Y[i]);
            visited.emplace(key);
        }
    }
    for(int i=0; i<N; i++){
        // if i does not exist in STUCK
        if(stuck.find(i)==stuck.end()){
            // infinity;
            cout<<"Infinity"<<endl;
        }
        else{
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
