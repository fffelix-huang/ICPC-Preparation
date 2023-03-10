template<int ALPHABET = 26, char MIN_CHAR = 'A'>
struct DynamicKMP {
	vi p;
	vector<array<int, ALPHABET>> dp;
	void push(char c) {
		int v = c - MIN_CHAR;
		dp.EB();
		dp.back()[v] = sz(dp);
		if(p.empty()) {
			p.PB(0);
			return;
		}
		int i = sz(p);
		for(int j = 0; j < ALPHABET; ++j) {
			if(j == v) p.PB(dp[p[i - 1]][j]);
			else dp.back()[j] = dp[p[i - 1]][j];
		}
	}
	void pop() { p.PPB(); dp.PPB(); }
	int query() const { return p.back(); }
	vi query_all() const { return p; }
};
