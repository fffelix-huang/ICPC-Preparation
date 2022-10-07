struct SCC {
	int n;
	vector<vector<int>> g, h;
	SCC() : SCC(0) {}
	SCC(int _n) : n(_n), g(_n), h(_n) {}
	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].PB(v); h[v].PB(u);
	}
	vector<int> solve() {
		vector<int> id(n), top;
		top.reserve(n);
		function<void(int)> dfs1 = [&](int u) {
			id[u] = 1;
			for(auto v : g[u]) {
				if(id[v] == 0) dfs1(v);
			}
			top.PB(u);
		};
		for(int i = 0; i < n; ++i) {
			if(id[i] == 0) dfs1(i);
		}
		fill(id.begin(), id.end(), -1);
		function<void(int, int)> dfs2 = [&](int u, int x) {
			id[u] = x;
			for(auto v : h[u]) {
				if(id[v] == -1) dfs2(v);
			}
		};
		for(int i = n - 1, cnt = 0; i >= 0; --i) {
			int u = top[i];
			if(id[u] == -1) dfs2(u, cnt++);
		}
		return id;
	}
};
