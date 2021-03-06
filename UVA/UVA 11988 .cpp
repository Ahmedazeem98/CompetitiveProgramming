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
//x = atoill(s.c_str())
void fast()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int dx[] = { 0, 0, -1, 1, -1, 1, -1,1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1 ,-1};
int main()
{
	fast();
	string s;
	while (getline(cin, s))
	{
		string unnormal, sol, first;
		int i = 0;
		int c = 0;
		while (i < sz)
		{
			if (s[i] == '[' && i < sz)
			{
				i++;
				c++;
				while (s[i] != ']' && s[i] != '[' && i < sz)
					unnormal += s[i], i++;
				if (s[i] == ']')
				{
					sol = unnormal + sol;
					unnormal.clear();
					c--;
				}
				else
				{
					sol = unnormal + sol;
					unnormal.clear();
				}
				if (c == 0)
				{
					while (s[i] != ']' && s[i] != '[' && i < sz)
						first += s[i], i++;
				}
			}
			else
			{
				if (s[i]!=']')
				{
					while (s[i] != ']' && s[i] != '[' && i < sz)
						first += s[i], i++;
				}
				else
					c--, i++;
			}
		}
		cout << sol << first << endl;
	}
	return 0;
}
