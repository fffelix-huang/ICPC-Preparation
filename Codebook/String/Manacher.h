template<class T>
vector<int> manacher_odd(const vector<T>& a) {
	vector<T> b(1, -87);
	b.insert(b.end(), ALL(a));
	b.PB(-69);
	int n = SZ(b);
	vector<int> z(n);
	z[0] = 1;
	for(int i = 1, l = -1, r = 1; i <= n; ++i) {
		if(i < r) z[i] = min(z[l + r - i], r - i);
		while(b[i - z[i]] == b[i + z[i]]) z[i]++;
		if(i + z[i] - 1 > r) {
			l = i - z[i] + 1;
			r = i + z[i] - 1;
		}
	}
	return vector<int>(1 + ALL(z) - 1);
}
