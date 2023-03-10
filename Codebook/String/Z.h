template<class T>
vi z_algorithm(const vector<T>& a) {
	int n = sz(a);
	vi z(n);
	for(int i = 1, j = 0; i < n; ++i) {
		if(i <= j + z[j]) z[i] = min(z[i - j], j + z[j] - i);
		while(i + z[i] < n && a[i + z[i]] == a[z[i]]) z[i] += 1;
		if(i + z[i] > j + z[j]) j = i;
	}
	return z;
}
