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
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        int sum = 0;
        for(int i=0; i<N; i++){
            int x; cin>>x; arr.push_back(x);
            sum+=x;
        }
        if(N==1){
            if(arr[0]==0) cout<<"1 2"<<endl;
            if(arr[0]==1) cout<<"2 1"<<endl;
            continue;
        }
        if(arr[0]==1){
            cout<<N+1<<" ";
            for(int i=0; i<N; i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            continue;
        }
        if(arr[N-1]==0){
            for(int i=0; i<N; i++){
                cout<<i+1<<" ";
            }
            cout<<N+1<<" ";
            cout<<endl;
            continue;
        }

        pii x=make_pair(-1, -1);
        for(int i=0; i<N-1; i++){
            if(arr[i]==0 && arr[i+1]==1) x= make_pair(i, i+1);
        }
        for(int i=0; i<N; i++){
            if(x.first==i){
                cout<<x.first+1<<" "<<N+1<<" ";
            }
            else cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

