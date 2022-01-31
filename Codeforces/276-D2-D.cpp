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
    long L, R; cin>>L>>R;
   // if(L==R) cout<<0<<endl;
    v<int> a(70);
    v<int> b(70);
    long temp =1;
    v<long> p2;
    while(temp<(long)1e18){
        p2.push_back(temp);
        temp*=2;
    }
    temp = L;
    for(int i=(int)p2.size()-1 ; i>=0; i--){
        if(p2[i]<=temp){
            temp-=p2[i];
            a[i] = 1;
        }

    }
    temp=R;
    for(int i=(int)p2.size()-1 ; i>=0; i--){
        if(p2[i]<=temp){
            temp-=p2[i];
            b[i] = 1;
        }
    }
    /*for(int i=0; i<70; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<70; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    int idx = -1;
    for(int i=69; i>=0; i--){
        if(b[i]==1 && a[i]==0){
            idx=i;
            break;
        }
    }

    long ans = 0;
    for(int i=0; i<p2.size(); i++){
        if(i<=idx) ans+=p2[i];
    }
    cout<<ans<<endl;


    return 0;
}

