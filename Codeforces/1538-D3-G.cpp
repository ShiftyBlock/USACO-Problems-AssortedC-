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
bool valid(long X, long Y, long A, long B, long K){
    X-=A*K;
    Y-=A*K;
    int leftover = B-A;
    if(X<0 || Y<0) return false;
    if(leftover==0) return true;
    long ct = 0;
    ct+=X/leftover;
    ct+=Y/leftover;
    if(ct>=K) return true;
    return false;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int X, Y, A, B; cin>>X>>Y>>A>>B;
        if(A>B){
            int temp = A; A=B; B=temp;
        }
        int low = 0;
        int high = 1<<30;
        while(low!=high){
            int mid = (low+high)/2;
            if(valid(X,Y, A,B, mid)){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        cout<<low-1<<endl;
    }
    return 0;
}

