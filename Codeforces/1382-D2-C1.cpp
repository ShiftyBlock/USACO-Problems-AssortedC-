/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
//#define endl "\n"
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
        //ios_base::sync_with_stdio(0);
       // cin.tie(0);
    }

}

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> a,b;
        for(int i=0; i<N; i++){
            char c; cin>>c; a.push_back(c-'0');
        }

        for(int i=0; i<N; i++){
            char c; cin>>c; b.push_back(c-'0');
        }
        v<int> ans;
        for(int i=N-1; i>=0; i--){
            if(a[i]==b[i]) continue;
            if(a[0] == b[i]){
                ans.push_back(1);
                a[0] ^=1;
            }
            ans.push_back(i+1);
            for(int j=0; j<=i; j++){
                a[j] ^=1;
            }
            reverse(a.begin(), a.begin()+i+1);

        }
        cout<<ans.size()<<" ";
        for(int num: ans){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}

