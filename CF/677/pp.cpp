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
	int N; cin>>N;
	v<int> arr;
	int biggest=0;
	for (int i = 0; i < N; ++i)
	{
		/* code */
		int nu; cin>>nu;
		arr.push_back(nu);
		biggest= max(biggest,nu);
	}
	bool finish=false;
	for (int i = 0; i < N; ++i)
	{
		bool yay=false;
		if(arr[i]==biggest){
			if(i-1>=0) if(arr[i-1]<arr[i]) yay=true;
			if(i+1<N) if(arr[i+1]<arr[i]) yay=true;
		}
		if(yay) {
			cout<<i+1<<endl;
			finish=true;
			break;
		}
	}
	if(!finish) cout<<-1<<endl;

}
    

    return 0;
}







