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

    int tcs;
    cin>>tcs;
    while(tcs-->0){
    	int N;
    	cin>>N;
    	v<int> arr;
    	bool allsame=true;
    	for (int i = 0; i < N; ++i)
    	{
    		int nu;
    		cin>>nu;
    		arr.push_back(nu);
    		if(i!=0){
    			if(arr[i-1]!=nu) allsame=false;
    		}
    		/* code */
    	}
    	if(allsame){
    		cout<<"NO"<<endl;
			continue;
    	}
    	else{
			cout<<"YES"<<endl;
			int idx=-1;
			for (int i = 1; i < N; ++i)
			{
				if(arr[i]!=arr[0]){
					idx=i;
					cout<<0<<" "<<i<<endl;
				}
			}
			for (int i = 1; i < N; ++i)
			{
				if(arr[i]==arr[0]){
					cout<<idx<<" "<<i<<endl;
				}
			}
    	}

    }
    

    return 0;
}







