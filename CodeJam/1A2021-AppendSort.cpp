/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define long unsigned long long
#define v vector
#define stoi stol

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
    int tcss = tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<long> arr;
        for(int i=0; i<N; i++){
            long num;
            cin>>num;
            arr.push_back(num);
        }
        //minimum operations to make arr[i] > arr[i-1]
        int ans=0;
        for(int i=1; i<N; i++){
            if(arr[i]>arr[i-1]) continue;
            if(arr[i]==arr[i-1]){
                arr[i]*=10;
                ans++;
                continue;
            }
            string a = to_string(arr[i-1]);
            string b = to_string(arr[i]);
            int moves=0;
            int j=0;
            bool nobreak=true;
            while(j<b.size()){
                if(a[j]<b[j]) {
                    while(a.size()!=b.size()){
                        b+="0";
                        ans++;
                    }
                    nobreak=false;
                    break;
                }
                if(a[j]> b[j]){
                    while(a.size()>=b.size()){
                        b+="0";
                        ans++;
                    }
                    nobreak=false;
                    break;
                }
                j++;
            }
            arr[i]= stol(b);
            if(!nobreak) continue;
            string temp;
            for(int k=j; k<a.size(); k++){
                temp+=a[k];
            }
            int t = stol(temp);
            t++;
            temp = to_string(t);
            bool allz =true;
            allz &= (temp[0]==1);
            for(int l=1; l<temp.size(); l++){
                if(temp[l]!='0') allz=false;
            }
            if(allz && temp.size()>1){
                for(int l=0; l<temp.size(); l++){
                    b+='0';
                    ans++;
                }
            }
            else{
                for(int l=0; l<temp.size(); l++){
                    b+=temp[l];
                    ans++;
                }
            }
            arr[i]= stol(b);
        }
        cout<<"Case #"<<tcss-tcs<<": "<<ans<<endl;
    }
    return 0;
}

