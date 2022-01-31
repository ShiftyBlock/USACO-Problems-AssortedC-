/*
ID: stupidbessiesmh
PROG: zerosum
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
v<string> arr;
int N;
void recurse(int cur, string s){
    if(cur>N){
        arr.emplace_back(s);
        return;
    }
    recurse(cur+1,  s+"+"+ to_string(cur));
    recurse(cur+1,  s+"-"+to_string(cur));
    recurse(cur+1,  s+" "+to_string(cur));
}
v<string> valid;
int main() {
    setIO("zerosum", 1);
    cin>>N;
    recurse(2, "1");
    for(string s: arr){
        int sum=0;
        int sign=1;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='-') {
                sign=-1;
                continue;
            }
            if(s[i]=='+') {
                sign=1;
                continue;
            }
            int j=i;
            string temp="";
            while(j<s.length() && s[j]!='+' && s[j]!='-'){
                if(s[j] ==' ') {
                    j++; continue;
                }
                temp+=s[j];
                j++;
            }
            i=j-1;
            sum+= sign * stoi(temp);
        }
        if(sum==0) valid.push_back(s);
    }
    sort(valid.begin(), valid.end());
    for(string s: valid){
        cout<<s<<endl;
    }

    return 0;
}

