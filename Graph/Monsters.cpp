// Problem: Monsters
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1194
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define M 1000000007
#define ll long long int
#define pb push_back
#define endl '\n'
#define pf push_front
#define all(x) x.begin(), x.end()
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<"   "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<"   "<<#y<<" "<<y<<"   "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define sz(x)	(ll)x.size()
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
#define endl '\n'
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
#define pi (3.14159265358979323846264338327950288)
template<typename T>
void printv(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout<<endl;
}
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
	//unordered_map<ll,ll>m1;
	//m1.reserve(1024);
	//m1.max_load_factor(0.25);

	struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//unordered_map<ll,ll, custom_hash>m1;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
//-------------------------------Template--Above-----------------------------------------------
ll dist[1001][1001];
ll d[1001][1001];
ll dir[1001][1001];
ll dx[4]={0,0,-1,1};
ll dy[4]={1,-1,0,0};/// UDLR
void solve(){
	ll n,m;cin>>n>>m;
	memset(dist,-1,sizeof(dist));
	memset(d,-1,sizeof(d));
	//memset(dir,-1,sizeof(dir));
	vector<string>v;
	for(ll i=0;i<n;i++){
		string s;cin>>s;
		v.pb(s);
	}
	queue<vector<ll> >q;ll x=0,y=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(v[i][j]=='M'){
				q.push({i,j,0});
			}
			if(v[i][j]=='A'){
				x=i,y=j;
			}
		}
	}
		bool flag=false;
	while(!q.empty()){
		//debug1(q.size())
		auto fr=q.front();
		q.pop();
		ll x1=fr[0];ll y1=fr[1];ll step=fr[2];
		if(x1<0 || x1>=n || y1<0 || y1>=m || v[x1][y1]=='#' || dist[x1][y1]!=-1){
			continue;
		}
		dist[x1][y1]=step;
		for(ll i=0;i<4;i++){
			q.push({x1+dx[i],y1+dy[i],step+1});
		}
	}
	string ans="";
	while(!q.empty())
	q.pop();
	q.push({x,y,0,0});
	while(!q.empty()){
		auto fr=q.front();q.pop();
		ll x1=fr[0];ll y1=fr[1];ll step=fr[2];ll direc=fr[3];
		if(x1<0 || x1>=n || y1<0 || y1>=m || v[x1][y1]=='#' || (dist[x1][y1]>=0 and dist[x1][y1]<=step) || d[x1][y1]!=-1)
		continue;
		dir[x1][y1]=direc;
		//debug2(direc,dir[x1][y1])
		d[x1][y1]=step;
		if(x1==0 || x1==n-1 || y1==0 || y1==m-1){
			flag=true;
			
			//debug2(x,y)
			while(x1!=x || y1!=y){
				//debug3(x1,y1,dir[x1][y1])
				if(dir[x1][y1]==1){
				ans.pb('R');
				y1--;
				}
				else if(dir[x1][y1]==2){
				ans.pb('L');
				y1++;
				}
				else if(dir[x1][y1]==3){
				ans.pb('U');
				x1++;
				}
				else if(dir[x1][y1]==4){
				ans.pb('D');
				x1--;
				}
			}
			break;
		}
		for(ll i=0;i<4;i++){
			q.push({x1+dx[i],y1+dy[i],step+1,i+1});
		}
	}
	if(flag){
		cout<<"YES\n";
		reverse(all(ans));
		cout<<ans.length()<<endl;
		cout<<ans<<endl;
		return;
	}
	else
	cout<<"NO\n";
    return;
}
int main()
{
    boost
    ll t;
    t=1;
   // cin>>t;
    for(ll i=1;i<=t;i++){
    	solve();
	}
    return 0;
}
