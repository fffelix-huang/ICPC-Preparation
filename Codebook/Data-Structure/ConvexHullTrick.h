struct Line_t {
	mutable ll k, m, p;
	inline bool operator<(const Line_t& o) const { return k < o.k; }
	inline bool operator<(ll x) const { return p < x; }
};
// return maximum (with minimum use negative coefficient and constant)
struct CHT : multiset<Line_t, less<>> {
	// (for doubles, use INF = 1/.0, div(a,b) = a/b)
	static const ll INF = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if(y == end()) {
			x->p = INF;
			return 0;
		}
		if(x->k == y->k) x->p = (x->m > y->m ? INF : -INF);
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add_line(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll get(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
