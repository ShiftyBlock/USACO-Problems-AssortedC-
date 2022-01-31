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
long stresstest(string s){
    int N = s.length();
    long sum =N;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            string cur = s.substr(i, j-i+1);
            int last = -1;
            bool valid = true;
            for(int k=0; k<cur.length(); k++){
                if(last!=-1){
                    if(cur[last]=='0'){
                        if(cur[k]=='0'){
                            if((k-last)%2!=0) valid=false;
                        }
                        if(cur[k]=='1'){
                            if((k-last)%2!=1) valid=false;
                        }
                    }
                    if(cur[last]=='1'){
                        if(cur[k]=='1'){
                            if((k-last)%2!=0) valid=false;
                        }
                        if(cur[k]=='0'){
                            if((k-last)%2!=1) valid=false;
                        }
                    }
                }
                if(cur[k]!='?') last = k;
            }
            if(valid) sum++;
        }
    }
    return sum;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        string s; cin>>s;
        int N = s.length();
        int i=0;
        long sum = 0;
        v<pii> arr;
        while(i<N){
            int j= i+1;
            char last = s[i];
            int l =i;
            while(j<N){
                if(s[j]=='0'){
                    if(last =='0'){
                        if((j-l)%2==0){
                            last = s[j];
                            l=j;
                            j++;
                            continue;
                        }
                        else break;
                    }
                    if(last=='1'){
                        if((j-l)%2==1){
                            l=j;
                            last = s[j];
                            j++;
                            continue;
                        }
                        else break;
                    }
                    if(last=='?'){
                        last =s[j];
                        l=j;
                        j++;
                        continue;
                    }
                }
                if(s[j] =='1'){
                    if(last =='0'){
                        if((j-l)%2==1){
                            last = s[j];
                            l=j;
                            j++; continue;
                        }
                        else break;
                    }
                    if(last=='1'){
                        if((j-l)%2==0){
                            last=s[j];
                            l=j;
                            j++; continue;
                        }
                        else break;
                    }
                    if(last=='?'){
                        last =s[j];
                        l=j;
                        j++;
                        continue;
                    }
                }
                if(s[j]=='?') {
                    j++;
                    continue;
                }
            }
            int segment = j-i;
            arr.emplace_back(i,j);
            i=j;
        }
        //[i,j)
        v<pii> qmark;
        i=0;
        while(i<N){
            if(s[i]!='?') {
                i++; continue;
            }
            int j= i+1;
            while(j<N) {
                if(s[j]!='?') break;
                j++;
            }
            qmark.emplace_back(i, j);
            i=j;
        }
        i=0;
        set<pii> used;
        for(int k=0; k<qmark.size(); k++){
            int idx = lower_bound(arr.begin(), arr.end(), make_pair(qmark[k].second, (long)0)) - arr.begin();
            if(idx==arr.size()) continue;
            if(arr[idx].first != qmark[k].second) continue;
            int len1 = arr[idx].second - arr[idx].first;
            int len2 = qmark[k].second - qmark[k].first;
            sum+=(long)(len1+len2) * (len1+len2+1)/2;
            used.emplace(arr[idx]);
            //overcounting 1
            sum-= (long)len2*(len2+1)/2;
        }
        for(pii x: arr){
            if(used.find(x)!=used.end()) continue;
            int len1 = x.second - x.first;
            sum+=(long)(len1)*(len1+1)/2;
        }
        //cout<<stresstest(s)<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
// 3, 5, 4, 5,4,5