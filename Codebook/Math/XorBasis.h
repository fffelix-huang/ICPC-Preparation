template<int LOG> struct XorBasis {
	bool zero = false;
	int cnt = 0;
	ll p[LOG] = {};
	vector<ll> d;
	void insert(ll x) {
		for(int i = LOG - 1; i >= 0; --i) {
			if(x >> i & 1) {
				if(!p[i]) {
					p[i] = x;
					cnt += 1;
					return;
				} else x ^= p[i];
			}
		}
		zero = true;
	}
	ll get_max() {
		ll ans = 0;
		for(int i = LOG - 1; i >= 0; --i) {
			if((ans ^ p[i]) > ans) ans ^= p[i];
		}
		return ans;
	}
	ll get_min() {
		if(zero) return 0;
		for(int i = 0; i < LOG; ++i) {
			if(p[i]) return p[i];
		}
	}
	bool include(ll x) {
		for(int i = LOG - 1; i >= 0; --i) {
			if(x >> i & 1) x ^= p[i];
		}
		return x == 0;
	}
	void update() {
		d.clear();
		for(int j = 0; j < LOG; ++j) {
			for(int i = j - 1; i >= 0; --i) {
				if(p[j] >> i & 1) p[j] ^= p[i];
			}
		}
		for(int i = 0; i < LOG; ++i) {
			if(p[i]) d.PB(p[i]);
		}
	}
	ll get_kth(ll k) {
		if(k == 1 && zero) return 0;
		if(zero) k -= 1;
		if(k >= (1LL << cnt)) return -1;
		update();
		ll ans = 0;
		for(int i = 0; i < SZ(d); ++i) {
			if(k >> i & 1) ans ^= d[i];
		}
		return ans;
	}
};
