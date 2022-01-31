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
//make everything even
// first merge consecutive odds
//then merge the endpoint odds if there are still any remaining
//

int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr.push_back(num);
    }
    int gcd = arr[0];
    for(int i=1;i<N; i++){
        gcd = __gcd(gcd, arr[i]);
    }
    if(gcd!=1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    int moves = 0;
    for(int i=0; i<N-1; i++){
        if(arr[i]%2==1 && arr[i+1]%2==1){
            arr[i] = 0;
            arr[i+1] = 0;
            i++;
            moves++;
            continue;
        }
    }
    for(int i=0; i<N; i++){
        if(arr[i]%2==1){
            moves+=2;
            continue;
        }
    }

    cout<<"YES"<<endl;
    cout<<moves<<endl;

    return 0;
}

