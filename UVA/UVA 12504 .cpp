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
	int t;
	cin >> t;
	while (t--)
	{
		map<string, string>old;
		map<string, string>neew;
		map<char, set<string>>mp;
		rep(k, 2)
		{
			string s, ss, f;
			cin >> s;
			rep(i, sz)
			{
				if (isalpha(s[i]))
				{
					while (isalpha(s[i]))
						ss += s[i], i++;
					i++;
					while (isdigit(s[i]))
						f += s[i], i++;
					if (!k)
						old[ss] = f;
					else
						neew[ss] = f;
					f = "", ss = "";
				}
			}
		}
		for (auto e : neew)
		{
			if (old[e.first]=="")
				mp['+'].insert(e.first);
			else if (old[e.first] != "")
			{
				if (e.second != old[e.first])
					mp['*'].insert(e.first);
			}
		}
		for (auto e : old)
		{
			if (neew[e.first] == "")
				mp['-'].insert(e.first);
		}
		if (mp.size() == 0)
			cout << "No changes" << endl << endl;
		else
		{
			set<string>::iterator it;
			if (mp['+'].size() != 0)
			{
				bool l = 0;
				it = mp['+'].begin();
				cout << "+";
				for (; it != mp['+'].end(); it++)
				{
					if (l)
						cout << "," << *it;
					else
						cout << *it;
					l = 1;
				}
				cout << endl;
			}
			if (mp['-'].size() != 0)
			{
				bool l = 0;
				it = mp['-'].begin();
				cout << "-";
				for (; it != mp['-'].end(); it++)
				{
					if (l)
						cout << "," << *it;
					else
						cout << *it;
					l = 1;
				}
				cout << endl;
			}
			if (mp['*'].size() != 0)
			{
				bool l = 0;
				it = mp['*'].begin();
				cout << "*";
				for (; it != mp['*'].end(); it++)
				{
					if (l)
						cout << "," << *it;
					else
						cout << *it;
					l = 1;
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	return 0;
}
