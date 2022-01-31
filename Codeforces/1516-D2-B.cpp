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
// you only need 2 or 3 blocks of the same xor value
// because if you have 4 you can collapse into 2
// and if you have 5 you can collapse into 3
// so to find 2, we can just try all prefixes/suffixes
// and to find 3, we can try all prefix/suffix pairs, and the middle is the last block
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        v<int> prefix(N);
        v<int> suffix(N);
        int total=0;
        for(int i=0; i<N; i++){
            int n;cin>>n;
            arr.push_back(n);
            total^=arr[i];
        }
        for(int i=0; i<N; i++){
            if(i==0) prefix[i]= arr[i];
            else{
                prefix[i] = arr[i] ^ prefix[i-1];
            }
        }
        for(int i=N-1; i>=0; i--){
            if(i==N-1) suffix[i]= arr[i];
            else{
                suffix[i] = arr[i] ^ suffix[i+1];
            }
        }
        //check for 2
        bool valid1=false;
        /*
        for(int i=0; i<N; i++){
            cout<<prefix[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<N; i++){
            cout<<suffix[i]<<" ";
        }
        cout<<endl;
         */
        for(int i=0; i<N-1; i++){
            if(prefix[i] == suffix[i+1]){
                valid1=true;
            }
        }
        //check for 3
        bool valid2=false;
        for(int i=0; i<N-1; i++){
            for(int j=i+2; j<N; j++){
                if(prefix[i] == suffix[j] && prefix[i]==(total^prefix[i]^suffix[j])){
                    valid2=true;
                }
            }
        }
        if(valid1 || valid2){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;


    }
    return 0;
}

