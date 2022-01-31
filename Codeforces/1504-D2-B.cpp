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
        string a,b;cin>>a>>b;
        v<int> zeros, ones;
        zeros.push_back((a[0]=='0'));
        ones.push_back((a[0]=='1'));
        for(int i=1; i<N; i++){
            zeros.push_back(zeros[i-1] +(a[i]=='0'));
            ones.push_back(ones[i-1] + (a[i]=='1'));
        }
        int turn = 0;
        int i =N-1;
        bool valid = true;
        while(i>=0){
            if(turn==0){
                if(a[i] !=b[i]){
                    if(zeros[i] != ones[i]) {
                        valid= false;
                        break;
                    }
                    turn++;
                    turn%=2;
                }
            }
            if(turn==1){
                if(a[i] ==b[i]){
                    if(zeros[i] != ones[i]) {
                        valid= false;
                        break;
                    }
                    turn++;
                    turn%=2;
                }
            }
            i--;
        }
        if(valid) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

