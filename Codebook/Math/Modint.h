template<int m>
struct modint {
	static constexpr int mod() { return m; }
	modint() : val(0) {}
	modint(long long v) {
		v %= mod();
		if(v < 0) v += mod();
		val = v;
	}
	const int& operator()() const { return val; }
	modint& operator+=(const modint& other) {
		val += other.val;
		if(val >= mod()) val -= mod();
		return *this;
	}
	modint& operator-=(const modint& other) {
		val -= other.val;
		if(val < 0) val += mod();
		return *this;
	}
	modint& operator*=(const modint& other) {
		val = 1LL * val * other.val % mod();
		return *this;
	}
	modint& operator/=(const modint& other) {
		auto eg = inv_gcd(other.val, mod());
		assert(eg.F == 1);
		return *this *= eg.S;
	}
	template<class T> modint& operator+=(const T& other) { return *this += modint(other); }
	template<class T> modint& operator-=(const T& other) { return *this -= modint(other); }
	template<class T> modint& operator*=(const T& other) { return *this *= modint(other); }
	template<class T> modint& operator/=(const T& other) { return *this /= modint(other); }
	modint operator+() const { return *this }
	modint operator-() const { return modint() - *this; }
	modint operator+(const modint& other) { return modint(*this) += other; }
	modint operator-(const modint& other) { return modint(*this) -= other; }
	modint operator*(const modint& other) { return modint(*this) *= other; }
	modint operator/(const modint& other) { return modint(*this) /= other; }
	int val;
};
template<int m, class T> modint<m> operator+(const T& lhs, const modint<m>& rhs) {
	return modint<m>(lhs) += rhs;
}
template<int m, class T> modint<m> operator-(const T& lhs, const modint<m>& rhs) {
	return modint<m>(lhs) -= rhs;
}
template<int m, class T> modint<m> operator*(const T& lhs, const modint<m>& rhs) {
	return modint<m>(lhs) *= rhs;
}
template<int m, class T> modint<m> operator/(const T& lhs, const modint<m>& rhs) {
	return modint<m>(lhs) /= rhs;
}
