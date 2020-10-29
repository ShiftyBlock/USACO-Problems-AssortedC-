#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define rep(i,a,b) for(int i=a; i<b; i++)
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("", 0);

    int tcs;
    cin>>tcs;
    while(tcs-->0){
        string s;
        cin>>s;
        int a=0; int b=0;
        int leftb=0;
        int lefta=0;
        for (int i = 0; i < s.length(); ++i)
        {
           if(i==0) {
                if(s[i]=='A') a++;
                else b++;
           }
           else{
            
                if(s[i-1]=='B'){
                    if(s[i]=='A') {
                        leftb+=b%2;
                        lefta+= a;
                        a=0; b=0;
                    }
                }
                if(s[i]=='A') {
                    a++;
                }
                if(s[i]=='B') {
                    b++;
                }
                int temp=a;
                a= max(0,a-b);
                b=max(0,b-temp); 
                if(lefta>0 && b>0){
                    int temp=lefta;
                    lefta=max(0, lefta-b);
                    b= max(0, b-temp);
                }
                if(lefta==0){
                    leftb+=b;
                    leftb%=2;
                    b=0;
                }

           }
        }
        leftb+=b%2;
        lefta+=a;
        int total=0;
        total+=(leftb)+lefta;
        cout<<total<<endl;
    	
    }

    return 0;
}















