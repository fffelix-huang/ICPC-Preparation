struct ODT {
	struct S {
		int l, r;
		mutable int v;
		S(int L, int R = -1, int V = 0) : l(L), r(R), v(V) {}
		bool operator<(const S& s) const { return l < s.l; }
	};
	using IT = set<S>::iterator;
	set<S> seg;
	ODT() { seg.insert(S(0, maxn)); }
	IT split(int x) {
		IT it = --seg.upper_bound(S(x));
		if(it->l == x) return it;
		int l = it->l, r = it->r, v = it->v;
		seg.erase(it);
		seg.insert(S(l, x - 1, v));
		return seg.insert(S(x, r, v)).first;
	}
	void assign(int l, int r, int v) {
		IT itr = split(r + 1), it = split(l);
		seg.erase(it, itr);
		seg.insert(S(l, r, v));
	}
};