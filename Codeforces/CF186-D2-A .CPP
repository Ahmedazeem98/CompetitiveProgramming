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
#define allvr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
void fast()
{
#ifndef ONLINE_JUDGE

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}int main()
{
	fast();
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size())
		return cout << "NO", 0;
	int c = 0;
	pair<int, int>pr = { -1, -1 };
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			c++;
			if (pr.first == -1)
				pr.first = i;
			else if (pr.second == -1)
				pr.second = i;
			else
				return cout << "NO", 0;
		}
	}
	if (c == 0 || c == 2)
	{
		if (c)
		{
			swap(s1[pr.first], s1[pr.second]);
			if (s1 == s2)
				cout << "YES";
			else
				cout << "NO";
		}
		else
			cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}
