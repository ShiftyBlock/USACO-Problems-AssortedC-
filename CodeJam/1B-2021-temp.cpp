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
//solves A = 1, B=2 case
// i think full credit is like strong induction
// if we use the example 2,4
// 4 -> 2
// 5 -> 1, 3
// 6 -> 2 , 4
// 7 -> 3, 5
// 8 -> 4, 6
// 9 -> 5, 7
//you get the point

long fib[1001][21];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    int temp = tcs;
    while(tcs-->0){
        int N, A,B; cin>>N>>A>>B;
        v<int> arr;
        for(int i=0; i<N; i++){
            int n; cin>>n; arr.push_back(n);
        }
        //observation
        //the number of metals we can make is fib
        for(int i=1; i<=A; i++ ){
            fib[i][i] = 1;
        }
        for(int i=A+1; i<=B; i++){
            fib[i][i] = 1;
        }
        for(int i=B+1; i<1001; i++){
            for(int j=0; j<21; j++){
                fib[i][j] += fib[i-A][j];
                fib[i][j] +=fib[i-B][j];
            }
        }
        /*for(int i=0; i<101; i++){
            for(int j=0; j<21; j++){
                cout<<fib[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
        v<int> target(21);
        for(int i=1; i<=N; i++){
            for(int j=0; j<21; j++){
                int x = arr[i-1];
                int y = fib[i][j];
                target[j]+= arr[i-1] * fib[i][j];
            }
        }
        /*cout<<"TARGET"<<endl;
        for(int i=0; i<21; i++){
            cout<<target[i]<<" ";
        }
        cout<<endl;*/
        int ans=-1;

        for(int i=1; i<1001; i++){
            bool allgood=true;
            int tst = max(0, (int) (target[A]-fib[i][A]));
            fib[i][B] -= tst;
            fib[i][A] +=tst;
            for(int j=0; j<21; j++){
                if(fib[i][j]< target[j]){
                    allgood=false;
                    break;
                }
            }
            if(allgood){
                ans=i;
                break;
            }
        }
        if(ans==-1){
            cout<<"Case #"<<temp-tcs<<": "<<"IMPOSSIBLE"<<endl;
        }
        else cout<<"Case #"<<temp-tcs<<": "<<ans<<endl;
        for(int i=0; i<1001; i++){
            for(int j=0; j<21; j++){
                fib[i][j] = 0;
            }
        }

    }
    return 0;
}

