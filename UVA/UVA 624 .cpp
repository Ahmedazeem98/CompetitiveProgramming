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
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	int n, x;
	while (cin >> n)
	{
		cin >> x;
		vector<int>v(x);
		rep(i, x)
			cin >> v[i];
		int sum = 0, mx = -1;
		vector<int>st;
		vector<int>ans;
		for (int i = (1 << x) - 1; i > 0; i--)
		{
			int j = i, t = 0;
			while (j)
			{
				if (j & 1)
					st.pb(v[t]);
				t++;
				j >>= 1;
			}
			for (auto e : st)
				sum += e;
			if (sum <= n)
			{
				if (sum > mx)
				{
					mx = sum;
					ans = st;
				}
			}
			sum = 0;
			st.clear();
		}
		rep(i, ans.size())
			cout << ans[i] << " ";
		cout << "sum:" << mx << endl;
	}
	return 0;
}
