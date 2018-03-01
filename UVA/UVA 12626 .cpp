#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define allr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
//x = atoi(s.c_str())
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);}
int main()
{
    fast();
    	int t;
	cin>>t;
	while(t--)
	{
	    map<char,int>mp;
	    map<char,int>::iterator it;
	    string s,ss="311121",d="AGIMRT";
	    cin>>s;
	    rep(i,sz)
	    {
	        mp[s[i]]++;
	    }
	    int mn=1000000,c=0;
	    for(it=mp.begin();it!=mp.end();it++)
	    {
	        if(binary_search(all(d),it->first))
            {
	           int x=ss[c++]-'0';
	           x=it->second/x;
	           mn=min(x,mn);
            }
	    }
	    if(c!=6 || mn==1000000)
            mn=0;
	    cout<<mn<<endl;
	}
    return 0;
}
