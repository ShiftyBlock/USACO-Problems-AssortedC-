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
        string s;cin>>s;
       for(int i=0; i<N; i++){
           int j=i;
           while(j<N){
               if(s[j]=='?') j++;
               else break;
           }
           for(int k=i; k<j; k++){
               if(k%2==0)s[k]='B';
               if(k%2==1)s[k]='R';
           }
           int left = i-1;
           int sum1=0;
           int sum2=0;
           while(left>=0){
               if(s[left]==s[i]) {
                   sum1++; left--;
               }
               else break;
           }
           int right =j;
           while(right<N){
               if(s[right]==s[j-1]) {
                   sum1++; right++;
               }
               else break;
           }
           for(int k=i; k<j; k++){
               if(k%2==1)s[k]='B';
               if(k%2==0)s[k]='R';
           }
           left = i-1;
           sum2=0;
           while(left>=0){
               if(s[left]==s[i]) {
                   sum2++; left--;
               }
               else break;
           }
           right =j;
           while(right<N){
               if(s[right]==s[j-1]) {
                   sum2++; right++;
               }
               else break;
           }
           if(sum1<sum2){
               for(int k=i; k<j; k++){
                   if(k%2==0)s[k]='B';
                   if(k%2==1)s[k]='R';
               }
           }
       }
        cout<<s<<endl;
    }
    return 0;
}

