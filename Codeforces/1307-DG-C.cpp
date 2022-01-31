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
string abc ="abcdefghiklmnopqrstuvwxyz";
int freq[27];
int main() {
    setIO("", 0);
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        freq[s[i]-'a']++;
    }
    long count1=0;
    for(int i=0; i<26; i++){
        count1 = max((int)count1, freq[i]);
    }
    long count2 = 0;
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(i==j){
                count2 = max(count2, (long)freq[i] * (freq[i] -1) /2);
                continue;
            }
            int A = 0;
            int B = 0;
            long temp = 0;
            for(int k=0; k<s.length(); k++){
                if(s[k] == abc[i]){
                    A++;
                }
                if(s[k] == abc[j]){
                    B++;
                    temp+=A;
                }
            }
            count2 = max(count2, temp);
        }
    }
    cout<<max(count1, count2)<<endl;
    return 0;
}

