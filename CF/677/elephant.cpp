#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)
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

   	long num;
   	cin>>num;
   	long sum=1;
   	for (int i = num/2+1; i <= num; ++i)
   	{
   		sum*=i;
   	}
   	for (int i = 1; i <=num/2; ++i)
   	{
   		sum/=i;
   	}
   	v<long> factorial;
   	for (int i = 0; i <= num/2-1; ++i)
   	{
   		if(i==0) factorial.push_back(1);
   		else factorial.push_back(factorial[i-1]*i);
   	}
   	sum*=factorial[num/2-1]*factorial[num/2-1];
   	sum/=2;
   	cout<<sum<<endl;
    

    return 0;
}
