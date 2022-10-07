template<class T>
vector<int> lcp_array(const vector<T>& s, const vector<int>& sa) {
	int n = SZ(s);
	assert(n >= 1);
	vector<int> rnk(n);
	for(int i = 0; i < n; i++) rnk[sa[i]] = i;
	vector<int> lcp(n - 1);
	int h = 0;
	for(int i = 0; i < n; i++) {
		if(h > 0) h--;
		if(rnk[i] == 0) continue;
		int j = sa[rnk[i] - 1];
		for(; j + h < n && i + h < n; h++) {
			if(s[j + h] != s[i + h]) break;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}
