#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
//x = atoi(s.c_str())
void fast()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		int p, x;
		cin >> p;
		cin.ignore();
		vector<int>v(p + 1);
		string s;
		rep(i, p)
		{
			getline(cin, s);
			string f;
			stringstream ss(s);
			while (ss >> f)
			{
				x = atoi(f.c_str());
				v[i + 1]++;
			}
		}
		int mx = *min_element(v.begin()+1,v.begin()+p);
		vector<int>ans;
		rep(i, p)
		{
			if (v[i + 1] == mx)
				ans.pb(i + 1);
		}
		rep(i, ans.size())
		{
			if (i < ans.size() - 1)
				cout << ans[i] << " ";
			else
				cout << ans[i] << endl;
		}
	}
	return 0;
}
