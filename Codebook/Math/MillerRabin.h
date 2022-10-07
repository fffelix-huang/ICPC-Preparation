constexpr bool is_prime_constexpr(int n) {
	if(n <= 1) return false;
	if(n == 2 || n == 7 || n == 61) return true;
	if(n % 2 == 0) return false;
	ll d = (n - 1) >> __builtin_ctz(n - 1);
	constexpr ll bases[3] = {2, 7, 61};
	for(ll a : bases) {
		ll t = d;
		ll y = pow_mod_constexpr(a, t, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) return false;
	}
	return true;
}
template<int n> constexpr bool is_prime = is_prime_constexpr(n);

bool is_prime_ll(ull n) {
	static const vector<ull> SPRP = {
		2, 325, 9375, 28178, 450775, 9780504, 1795265022
	};
	if(n == 1 || n % 6 % 4 != 1) return (n | 1) == 3;
	ll t = __builtin_ctzll(n - 1), k = (n - 1) >> t;
	for(const ull &a : SPRP) {
		ull tmp = pow_mod(a, k, n);
		if(tmp <= 1 || tmp == n - 1) continue;
		for(int i = 0; i <= t; i++) {
			if(i == t) return false;
			tmp = __int128(tmp) * tmp % n;
			if(tmp == n - 1) break;
		}
	}
	return true;
}
