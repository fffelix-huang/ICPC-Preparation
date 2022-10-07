template<int ALPHABET, int (*f)(char)>
struct AhoCorasick {
	vector<array<int, ALPHABET>> trie, to;
	vector<int> fail, cnt;
	AhoCorasick() : AhoCorasick(vector<string>()) {}
	AhoCorasick(const vector<string>& S) {
		newNode();
		for(const auto& s : S) insert(s);
	}
	int insert(const string& s) {
		int p = 0;
		for(const char& c : s) p = next(p, f(c));
		cnt[p] += 1;
		return p;
	}
	inline int next(int u, int v) {
		if(!trie[u][v]) trie[u][v] = newNode();
		return trie[u][v];
	}
	void build_failure() {
		queue<int> que;
		for(int i = 0; i < ALPHABET; ++i) {
			if(trie[0][i]) {
				to[0][i] = trie[0][i];
				que.push(trie[0][i]);
			}
		}
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(int i = 0; i < 26; ++i) {
				if(trie[u][i]) to[u][i] = trie[u][i];
				else to[u][i] = to[fail[u]][i];
			}
			for(int i = 0; i < 26; ++i) {
				if(trie[u][i]) {
					int p = trie[u][i];
					int k = fail[u];
					while(k && !trie[k][i]) k = fail[k];
					if(trie[k][i]) k = trie[k][i];
					fail[p] = k;
					cnt[p] += cnt[k];
					que.push(p);
				}
			}
		}
	}
	inline int newNode() {
		int sz = (int) trie.size();
		trie.EB();
		to.EB();
		fill(ALL(trie.back()), 0);
		fill(ALL(to.back()), 0);
		fail.EB();
		cnt.EB();
		return sz;
	}
};
