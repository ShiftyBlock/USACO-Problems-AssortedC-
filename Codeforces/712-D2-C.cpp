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
int Y, X;
v<int> arr(3);
bool valid(){
    return arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == X;
}
int main() {
    setIO("", 0);
    cin>>X>>Y;
    arr[0] = Y;
    arr[1] = Y;
    arr[2]=Y;
    int i=0;
    while(true){
        if(valid()) break;
        int idx = i%3;
        int othersum = arr[(idx+1)%3 ] + arr[(idx+2)%3];
        arr[idx] = min(X,othersum-1);
        i++;
    }
    cout<<i<<endl;
    return 0;
}

