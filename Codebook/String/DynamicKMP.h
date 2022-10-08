template<int ALPHABET, int (*f)(char)>
struct DynamicKMP {
	vector<int> p;
	vector<array<int, ALPHABET>> dp;
	DynamicKMP() {}
	DynamicKMP(const string& s) {
		reserve(SZ(s));
		for(const char& c : s) push(c);
	}
	void push(char c) {
		int v = f(c);
		dp.EB();
		dp.back()[v] = SZ(dp);
		if(p.empty()) {
			p.PB(0);
			return;
		}
		int i = SZ(p);
		for(int j = 0; j < ALPHABET; ++j) {
			if(j == v) p.PB(dp[p[i - 1]][j]);
			else dp.back()[j] = dp[p[i - 1]][j];
		}
	}
	void pop() { p.PPB(); dp.PPB(); }
	int query() const { return p.back(); }
	vector<int> query_all() const { return p; }
	void reserve(int sz) { p.reserve(sz); dp.reserve(sz); }
};
