#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define SZ(a) ((int)a.size())
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define PB push_back
#define PPB pop_back
#define EB emplace_back
#define F first
#define S second

template<class T> inline bool chmin(T& a, const T& b) { if(a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if(a < b) { a = b; return true; } return false; }

const double EPS = 1e-9;
