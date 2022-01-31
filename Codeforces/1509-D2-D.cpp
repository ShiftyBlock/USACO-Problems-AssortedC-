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
void read(v<int> &a, int N){
    for(int i=0; i<N; i++){
        char c; cin>>c;
        a.push_back(c-'0');
    }
}
void solve(v<int> &ans, v<int> a, v<int> b, int i, int j){
    if(i>=j){
        while(i<a.size()){
            ans.push_back(a[i]);
            i++;
        }
    }
    else if(i<j){
        while(j<b.size()){
            ans.push_back(b[j]);
            j++;
        }
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        N*=2;
        v<int> a,b,c;
        read(a,N);
        read(b,N);
        read(c,N);
        int i=0; int j=0; int k=0;
        v<int> ans;
        while(i<N && j<N && k<N){
            if(a[i]==b[j] && b[j]== c[k] ){
                ans.push_back(a[i]);
                i++; j++; k++;
                continue;
            }
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++; j++;
                continue;
            }
            if(b[j]==c[k]){
                ans.push_back(b[j]);
                j++; k++;
                continue;
            }
            if(c[k] == a[i]){
                ans.push_back(a[i]);
                i++; k++;
                continue;
            }
        }
        if(i==N){
            solve(ans, b,c, j, k);
        }
        if(j==N){
            solve(ans, a,c, i, k);
        }
        if(k==N){
            solve(ans, a,b, i, j);
        }
        for(int num: ans){
            cout<<num;
        }
        cout<<endl;

    }
    return 0;
}

