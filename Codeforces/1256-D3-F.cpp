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
        string a, b; cin>>a>>b;
        long count =0;
        v<int> freq(26);
        for(int i=0; i<N; i++){
            freq[a[i]-'a']++;
            freq[b[i]-'a']--;
        }
        bool valid = true;
        for(int i=0; i<26; i++){
            if(freq[i]!=0) valid =false;
        }
        if(!valid) cout<<"NO"<<endl;
        else{
            for(int i=0; i<N; i++){
                freq[a[i]-'a']++;
            }
            bool instant = false;
            // if you have >1 character
            // you can just swap until they're next to each other
            //then make infinite swaps
            for(int i=0; i<26; i++){
                if(freq[i]>1) instant = true;
            }
            if(instant){
                cout<<"YES"<<endl;
            }
            else{
                //N is at most 26
                long count = 0;
                for(int i=0; i<N; i++){
                    if(a[i]!=b[i]){
                        auto x = a.find(b[i]);
                        count+= x-i;
                        a.erase(x, 1);
                        a.insert(i, 1, b[i]);
                    }
                }
                cout<<((count%2==0)?"YES":"NO")<<endl;
            }
        }
    }
    return 0;
}

