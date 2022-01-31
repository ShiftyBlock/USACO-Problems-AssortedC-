/*
ID: davidzh8
PROG: prefix
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
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
int dp[200001];
int main() {
    setIO("prefix", 1);
    //idea
    //dp[i] means that you can build a prefix of length i
    // dp[0] = 1 because you can always build empty
    v<string> arr;
    string cur;
    cin>>cur;
    while(cur!="."){
        arr.push_back(cur);
        cin>>cur;
    }
    string line="";
/*
    cin>>cur;
    while(cur!="."){
        line+=cur;
        cin>>cur;
    }
    */

    while(cin>>cur){
        line+=cur;
    }

    dp[0]=1;

    for(int i=0; i<line.length(); i++){
        if(dp[i]) {
            for (int j = 0; j < arr.size(); j++) {
                string curstr = arr[j];
                int curlen = curstr.length();
                if(i+curlen<=line.length()){
                    string nextstr = line.substr(i, curlen);
                    if(curstr == nextstr){
                        dp[i+curlen]=1;
                    }
                }
            }
        }
    }
    int MAX =0;
    for(int i=0; i<=line.length(); i++){
        if(dp[i]) MAX = max(i, MAX);
    }
    cout<<MAX<<endl;

    return 0;
}

