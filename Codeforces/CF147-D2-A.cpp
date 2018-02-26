#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <utility> 
#include <stdlib.h>  //atoi
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
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int freq[52];
int main()
{
	fast();
	string s, tok, d;
	getline(cin, s);
	stringstream ss(s);
	vector<string>v;
	while (ss >> tok)
	{
		if (tok.find(',') == -1 && tok.find('.')==-1 && tok.find('!')==-1 && tok.find('?')==-1)
			v.push_back(tok);
		else
		{
			string f;
			for (int i = 0; i < tok.size(); i++)
			{
				while (!isalpha(tok[i]) && i < tok.size())
				{
					if (tok[i] == ' ')
						i++;
					else
						f += tok[i], i++;
				}
				if (f.size())
					v.push_back(f), f.clear();
				while (isalpha(tok[i]) && i < tok.size())
					f += tok[i], i++;
				if (f.size())
					v.push_back(f), f.clear(), i--;
				
			}
		}
	}
	rep(i, vz - 1)
	{
		if (isalpha(v[i + 1][0]))
			cout << v[i] << " ";
		else
			cout << v[i] << v[i + 1] << " ", i++;
	}
	cout << v[vz - 1] << endl;

	return 0;
}
