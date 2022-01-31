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

void setIO(string name, int submit) {
   /* if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
*/
}
string abc = "abcdefghijklmnopqrstuvwxyz";
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            arr.push_back(num);
        }
        v<string> ans;
        string cur = "";
        for(int i=0; i<arr[0]; i++){
            cur+='a';
        }
        if(cur=="") cur ="a";
        ans.push_back(cur);
        for(int i=0; i<N; i++){
            if(arr[i] == 0){
                int next = 0;
                while(abc[next] == ans[i][arr[i]]){
                    next++;
                }
                cur = abc[next];
                if(i==N-1){
                    ans.push_back(cur); break;
                }
                for(int j=cur.length(); j<arr[i+1]; j++){
                    cur+='a';
                }
                ans.push_back(cur);
                continue;
            }
            cur = cur.substr(0, arr[i]);
            if(i == N-1) {
                ans.push_back(cur); break;
            }
            int next = 0;
            if(arr[i] < ans[i].length()){
                while(abc[next] == ans[i][arr[i]]){
                    next++;
                }
            }
            cur+=abc[next];
            for(int j=cur.length(); j<arr[i+1]; j++){
                cur+='a';
            }
            ans.push_back(cur);
        }
        for(string s: ans){
            cout<<s<<endl;
        }
    }
    return 0;
}

