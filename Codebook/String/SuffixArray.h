vi sa_is(const vi& s, int upper) {
	int n = sz(s);
	if(n == 0) return {};
	if(n == 1) return {0};
	if(n == 2) {
		if(s[0] < s[1]) return {0, 1};
		else return {1, 0};
	}
	vi sa(n);
	vector<bool> ls(n);
	for(int i = n - 2; i >= 0; i--) ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
	vi sum_l(upper + 1), sum_s(upper + 1);
	for(int i = 0; i < n; i++) {
		if(!ls[i]) sum_s[s[i]]++;
		else sum_l[s[i] + 1]++;
	}
	for(int i = 0; i <= upper; i++) {
		sum_s[i] += sum_l[i];
		if(i < upper) sum_l[i + 1] += sum_s[i];
	}
	auto induce = [&](const vi& lms) {
		fill(all(sa), -1);
		vi buf(upper + 1);
		copy(all(sum_s), buf.begin());
		for(auto d : lms) {
			if(d == n) continue;
			sa[buf[s[d]]++] = d;
		}
		copy(all(sum_l), buf.begin());
		sa[buf[s[n - 1]]++] = n - 1;
		for(int i = 0; i < n; i++) {
			int v = sa[i];
			if(v >= 1 && !ls[v - 1]) sa[buf[s[v - 1]]++] = v - 1;
		}
		copy(all(sum_l), buf.begin());
		for(int i = n - 1; i >= 0; i--) {
			int v = sa[i];
			if(v >= 1 && ls[v - 1]) sa[--buf[s[v - 1] + 1]] = v - 1;
		}
	};
	vi lms_map(n + 1, -1);
	int m = 0;
	for(int i = 1; i < n; i++) if(!ls[i - 1] && ls[i]) lms_map[i] = m++;
	vi lms;
	lms.reserve(m);
	for(int i = 1; i < n; i++) if(!ls[i - 1] && ls[i]) lms.PB(i);
	induce(lms);
	if(m) {
		vi sorted_lms;
		sorted_lms.reserve(m);
		for(int v : sa) if(lms_map[v] != -1) sorted_lms.PB(v);
		vi rec_s(m);
		int rec_upper = 0;
		rec_s[lms_map[sorted_lms[0]]] = 0;
		for(int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1], r = sorted_lms[i];
			int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
			int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
			bool same = true;
			if(end_l - l != end_r - r) {
				same = false;
			} else {
				while(l < end_l) {
					if(s[l] != s[r]) break;
					++l, ++r;
				}
				if(l == n || s[l] != s[r]) same = false;
			}
			if(!same) rec_upper++;
			rec_s[lms_map[sorted_lms[i]]] = rec_upper;
		}
		auto rec_sa = sa_is(rec_s, rec_upper);
		for(int i = 0; i < m; i++) sorted_lms[i] = lms[rec_sa[i]];
		induce(sorted_lms);
	}
	return sa;
}
