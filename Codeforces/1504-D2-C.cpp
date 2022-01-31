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
//split the string into segments
// then just do ((((((...))))) etc
// then make an inverse of that
// how to split string into segments :weary:
//wait nvm lets take the parity of 1s and 0s
// both parities must be even
// so we can first fill in 1s with (((( and the second half of 1s with ))))
// we cannot do the same thing with 0s
// but we can cancel out our 0s by doing ()()()() etc
// shoot the palindrome didnt even work lol
// if we take
// 100100111001 we cannot split into palindromes but it is valid
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        int a=0; int b =0;
        for(int i=0; i<N; i++){
            if(s[i]=='1') a++;
            else b++;
        }
        bool valid = true;
        valid&= s[0]=='1';
        valid&= s[N-1] =='1';
        valid&= a%2==0;
        valid&= b%2==0;
        if(!valid) {
            cout<<"NO"<<endl;
            continue;
        }
        v<char> arr(N);
        int ca = a;
        int cb = 0;
        for(int i=0; i<N; i++){
            // second half
            if(s[i]=='1'){
                if(2*ca <= a){
                    arr[i] = ')';
                }
                else{
                    arr[i] = '(';
                }
                ca--;
            }
            if(s[i]=='0'){
                if(cb%2==0){
                    arr[i]='(';
                }
                else arr[i]=')';
                cb++;
            }
        }
        cout<<"YES"<<endl;
        for(int i=0; i<N; i++){
            cout<<arr[i];
        }
        cout<<endl;
        for(int i=0; i<N; i++){
            if(s[i]=='1'){
                cout<<arr[i];
            }
            if(s[i]=='0'){
                if(arr[i]==')') cout<<'(';
                else cout<<')';
            }

        }
        cout<<endl;
    }

    return 0;
}

