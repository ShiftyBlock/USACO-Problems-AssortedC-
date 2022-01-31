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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        int K; cin>>K;
        int x,y; cin>>x>>y;
       if(x==y) {
           cout<<N<<" "<<N<<endl; continue;
       }

       v<pii >arr;
       arr.emplace_back(0,0);
        arr.emplace_back(0,0);
        arr.emplace_back(0,0);
        arr.emplace_back(0,0);
        int m = min(N-x, N-y);
        x+=m; y+=m;

        arr[1].first=x;
        arr[1].second=y;
        if(x==N){
            int move= N-y;
            x-=move; y+=move;
            arr[2].first=x; arr[2].second=y;
            move= x;
            x-=move; y-=move;
            arr[3].first=x; arr[3].second=y;
            move= y;
            x+=move; y-=move;
            arr[0].first=x; arr[0].second=y;
        }
        if(y==N){
            int move= N-x;
            x+=move; y-=move;
            arr[2].first=x; arr[2].second=y;
            move= y;
            x-=move; y-=move;
            arr[3].first=x; arr[3].second=y;
            move= x;
            x-=move; y+=move;
            arr[0].first=x; arr[0].second=y;
        }
        cout<<arr[K%4].first<<" "<<arr[K%4].second<<endl;






    }

    return 0;
}

