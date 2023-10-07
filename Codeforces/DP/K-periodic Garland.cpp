//#define KPR_111


#include<bits/stdc++.h>
using namespace std;


using ll= long long;
typedef pair<ll, ll>          pll;
typedef vector<ll>            vll;
typedef vector<pll>           vpll;
typedef vector<string>        vs;
typedef unordered_map<ll,ll>  umll;
typedef map<ll,ll>            mll;
#define pb                    push_back
#define eb                    emplace_back
#define sz                    size()
#define maxpq                 priority_queue<int>
#define minpq                 priority_queue<int, vector<int>, greater<int> >
#define f                     first
#define s                     second
#define vi                    vector<int>
#define vvi                   vector<vi>
#define vb                    vector<bool>
#define pii                   pair<int,int>
#define vpi                   vector<pii>
#define vvb                   vector<vb>
#define YES                   cout << "YES" << "\n"
#define NO                    cout << "NO" << "\n"
#define prDouble(x)           cout << fixed << setprecision(10) << x
#define ispowoftwo(n)         (!(n & (n-1)))
#define fo(i,m,n)             for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n)              fo(i,0,n)
#define rl(i,n,m)             for(int i=n;i>=m;i--)
#define all(v)                v.begin(),v.end()
#define uniq(v)               (v).erase(unique(all(v)),(v).end()) //if you sort it and use you get uniqe elements
#define mem(a, b)             memset(a, (b), sizeof(a))
#define ct(x,v)               count(v.begin(),v.end(),x)
#define mxe(v)                *max_element(v.begin(),v.end())
#define mne(v)                *min_element(v.begin(),v.end())
#define endl                  "\n"
#define inf                   (1LL<<30)



int m;
vi pf;
int getones(int i,int j){
	if(!i)return pf[j];
	return pf[j]-pf[i-1];
}
int dp[1000003][3];
int solve(int i,bool startone,string &s,int &k){

	if(i>=m)return 0;

	if(dp[i][startone]!=-1)return dp[i][startone];
	int ans=1e9;
	int n=s.sz;
	int j=min(m,i+k-1);
	if(!startone){
		if(s[i]=='0'){  
			int keepsame=solve(i+1,startone,s,k);
			int changeit=1+getones(i+1,j)+solve(i+k,!startone,s,k);
			ans=min({ans,keepsame,changeit});
		}
		else if(s[i]=='1'){
			int keepsame=getones(i+1,j)+solve(i+k,!startone,s,k);
			int changeit=1+solve(i+1,startone,s,k);
			ans=min({ans,keepsame,changeit});
		}
	}
	else{
		if(s[i]=='0'){
			int changeit=getones(i+1,j)+1+solve(i+k,startone,s,k);
			int keepsame=getones(i+1,m);
			ans=min({ans,keepsame,changeit});
		}
		else if(s[i]=='1'){
			int keepsame=getones(i+1,j)+solve(i+k,startone,s,k);
			int changeit=getones(i+1,m)+1;

			ans=min({ans,keepsame,changeit});
		}
	}

	return dp[i][startone]=ans;
}

void solve(){
	int n,k;
	cin>>n>>k;
	rep(i,n){
		rep(j,3){
			dp[i][j]=-1;
		}
	}
	// mem(dp,-1);//memset not working waste memset ,dont use it instead implement like this above
	string s;
	cin>>s;
	pf.resize(n);
	pf[0]=s[0]-'0';
	fo(i,1,n){
		pf[i]=pf[i-1]+s[i]-'0';
	}
	rep(i,n){
		if(s[i]=='1')m=i;
	}
	// rep(i,n)cout<<pf[i]<<" ";
	// cout<<endl;

	cout<<solve(0,0,s,k)<<endl;

}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for(int t = 0; t < tt; t++) {
		// mem(dp,-1);
		//cout << "Case #" << t+1 << ": ";
		solve();
		//cout << endl;
		#ifdef KPR_111
			cout << "__________________________" << endl;
		#endif
	}
}