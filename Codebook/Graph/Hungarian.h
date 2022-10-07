pair<ll, vector<pair<int, int>>> Hungarian(const vector<vector<ll>>& g) {
	const ll INF = LLONG_MAX;
	int n = SZ(g) + 1, m = SZ(g[0]) + 1;
	vector<vector<ll>> adj(n, vector<ll>(m));
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < m - 1; ++j) {
			adj[i + 1][j + 1] = g[i][j];
		}
	}
	vector<ll> u(n), v(m);
	vector<int> match(m);
	for(int i = 1; i < n; i++) {
		int w = 0;
		match[w] = i;
		vector<ll> dist(m, INF);
		vector<int> pred(m, -1);
		vector<bool> vis(m);
		while(match[w]) {
			vis[w] = true;
			int cur = match[w], nw = 0;
			ll delta = INF;
			for(int j = 1; j < m; j++) {
				if(!vis[j]) {
					ll edge = adj[cur][j] - u[cur] - v[j];
					if(edge < dist[j]) {
						dist[j] = edge;
						pred[j] = w;
					}
					if(dist[j] < delta) {
						delta = dist[j];
						nw = j;
					}
				}
			}
			for(int j = 0; j < m; ++j) {
				if(vis[j]) {
					u[match[j]] += delta;
					v[j] -= delta;
				} else dist[j] -= delta;
			}
			w = nw;
		}
		while(w) {
			int nw = pred[w];
			match[w] = match[nw];
			w = nw;
		}
	}
	vector<pii> res;
	for(int i = 1; i < n; ++i) res.EB(match[i] - 1, i - 1);
	return {-v[0], res};
}
