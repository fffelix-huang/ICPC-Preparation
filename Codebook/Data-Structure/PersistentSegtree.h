// 1. Set the value $a$ in array $k$ to $x$.
// 2. Calculate the sum of values in range $[a, b]$ in array $k$.
// 3. Create a copy of array $k$ and add it to the end of the list.
struct Node {
	ll val;
	Node* l;
	Node* r;
	Node(ll x = 0) : val(x), l(NULL), r(NULL) {}
	Node(Node* ll, Node* rr) : l(ll), r(rr) {
		val = (l ? l->val : 0) + (r ? r->val : 0);
	}
};
Node* build(int l, int r) {
	if(l + 1 == r) {
		ll x;
		cin >> x;
		return new Node(x);
	}
	int m = (l + r) / 2;
	return new Node(build(l, m), build(m, r));
}
Node* update(Node* v, int p, ll x, int l, int r) {
	if(l + 1 == r) return new Node(x);
	int m = (l + r) / 2;
	if(p < m) return new Node(update(v->l, p, x, l, m), v->r);
	else return new Node(v->l, update(v->r, p, x, m, r));
}
ll query(Node* v, int x, int y, int l, int r) {
	if(r <= x || l >= y) return 0;
	if(x <= l && r <= y) return v->val;
	int m = (l + r) / 2;
	return query(v->l, x, y, l, m) + query(v->r, x, y, m, r);
}
int main() {
	int n, q; cin >> n >> q;
	vector<Node*> version{build(0, n)};
	while(q--) {
		int tc;
		cin >> tc;
		if(tc == 1) {
			int k, p, x; cin >> k >> p >> x;
			--k, --p;
			version[k] = update(version[k], p, x, 0, n);
		} else if(tc == 2) {
			int k, l, r; cin >> k >> l >> r;
			--k, --l;
			cout << query(version[k], l, r, 0, n) << "\n";
		} else if(tc == 3) {
			int k; cin >> k;
			--k;
			version.push_back(version[k]);
		} else {
			assert(false);
		}
	}
	return 0;
}
