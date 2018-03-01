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
    string s;
    set<string>st;
    set<string>::iterator it;
    while(cin >> s)
    {
        string ss;
        rep(i,s.size())
        {
            if(isalpha(s[i]))
            {
                ss+=tolower(s[i]);
            }
            else
            {
              if(ss.size())
                 st.insert(ss);
                 ss.clear();
            }
        }
        if(ss.size())
           st.insert(ss);
    }
    for(it=st.begin();it!=st.end();it++)
        cout<<*it<<endl;
    return 0;
}
