struct splitmix64_hash {
	static ull splitmix64(ull x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	ull operator()(ull x) const {
		static const ull FIXED_RANDOM = RAND;
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class T, class U, class H = splitmix64_hash> using hash_map = gp_hash_table<T, U, H>;
template<class T, class H = splitmix64_hash> using hash_set = hash_map<T, null_type, H>;
