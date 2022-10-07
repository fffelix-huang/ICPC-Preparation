// @return
//	$\text{remainder, modulo}$
//			or
//	$0, 0$ if do not exist
pair<ll, ll> crt(const vector<ll>& r, const vector<ll>& m) {
	assert(SZ(r) == SZ(m));
	int n = SZ(r);
	// Contracts: 0 <= r0 < m0
	ll r0 = 0, m0 = 1;
	for(int i = 0; i < n; i++) {
		assert(1 <= m[i]);
		ll r1 = r[i] % m[i];
		if(r1 < 0) r1 += m[i];
		ll m1 = m[i];
		if(m0 < m1) {
			swap(r0, r1);
			swap(m0, m1);
		}
		if(m0 % m1 == 0) {
			if(r0 % m1 != r1) return {0, 0};
			continue;
		}
		ll g, im;
		tie(g, im) = inv_gcd(m0, m1);
		ll u1 = (m1 / g);
		if((r1 - r0) % g) return {0, 0};
		ll x = (r1 - r0) / g % u1 * im % u1;
		r0 += x * m0;
		m0 *= u1;
		if(r0 < 0) r0 += m0;
	}
	return {r0, m0};
}
