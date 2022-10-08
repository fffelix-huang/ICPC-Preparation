// find minimum
int Aliens(int l, int r, int k, const function<pii(int)>& f) {
	while(l < r) {
		int m = l + (r - l) / 2;
		auto [score, op] = f(m);
		if(op == k) return score - m * k;
		if(op < k) r = m;
		else l = m + 1;
	}
	return f(l).first - l * k;
}
