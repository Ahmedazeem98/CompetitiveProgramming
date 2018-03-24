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
	int a, b;
	while (cin >> a >> b && a && b)
	{
		vector<int>v(b);
		rep(i, b)
			cin >> v[i];
		map<vector<int>, bool>mp;
		vector<vector<int>>sol;
		for (int i = 1; i < (1 << b); i++)
		{
			vector<int>ans;
			int j = i, c = 0, sum = 0;
			while (j)
			{
				if (j & 1)
					ans.pb(v[c]), sum += v[c];
				c++;
				j >>= 1;
			}
			if (sum == a)
			{
				if (mp[ans] == 0)
				{

					sort(allr(ans));
					sol.pb(ans);
					mp[ans] = 1;
				}
			}
		}
		cout << "Sums of " << a << ":" << endl;
		if (sol.empty())
		{
			cout << "NONE" << endl;
			continue;
		}
		sort(allr(sol));
		rep(i, sol.size())
		{
			rep(j, sol[i].size() - 1)
				cout << sol[i][j] << "+";
			cout << sol[i][sol[i].size()-1] << endl;
		}
	}
	return 0;
}
