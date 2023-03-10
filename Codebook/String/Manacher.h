// Length: (z[i] - (i & 1)) / 2 * 2 + (i & 1)
vi manacher(const string& tmp) {
	string s = "&";
	int l = 0, r = 0;
	for(char c : tmp) s.PB(c), s.PB('%');
	int n = sz(s);
	vi z(n);
	for(int i = 0; i < n; ++i) {
		z[i] = r > i ? min(z[2 * l - i], r - i) : 1;
		while(s[i + z[i]] == s[i - z[i]]) z[i] += 1;
		if(z[i] + i > r) r = z[i] + i, l = i;
	}
	return z;
}
