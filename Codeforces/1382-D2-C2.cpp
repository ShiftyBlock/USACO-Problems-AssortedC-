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
//convert a to 0
// convert b to 0
//reverse b array
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
        v<int> ansA;
        if(a.size()==1){
            if(a[0]==1){
                ansA.push_back(1);
            }
        }
        for(int i=1; i<N; i++){
            if(a[i]==1 && a[i-1] ==0 ) {
                ansA.push_back(i); //i-1
            }
            if( a[i]==0 && a[i-1] ==1){
                ansA.push_back(i);
            }
            if((i==N-1 && a[i]==1)){
                ansA.push_back(i+1);
            }
        }
        v<int> ansB;
        if(b.size()==1){
            if(b[0]==1){
                ansB.push_back(1);
            }
        }
        for(int i=1; i<N; i++){
            if(b[i]==1 && b[i-1] ==0 ) {
                ansB.push_back(i); //i-1
            }
            if(( b[i]==0 && b[i-1] ==1 )){
                ansB.push_back(i);
            }
            if((i==N-1 && b[i]==1)){
                ansB.push_back(i+1);
            }
        }
        cout<<ansA.size()+ansB.size()<<" ";
        for(int num: ansA){
            cout<<num<<" ";
        }
        reverse(ansB.begin(), ansB.end());
        for(int num: ansB){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}

