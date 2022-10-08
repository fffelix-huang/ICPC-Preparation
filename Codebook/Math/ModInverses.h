vector<int> mod_inverse(int m, int n = -1) {
	assert(n < m);
	if(n == -1) n = m - 1;
	vector<int> inv(n + 1);
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; ++i) inv[i] = m - 1LL * (m / i) * inv[m % i] % m;
	return inv;
}
