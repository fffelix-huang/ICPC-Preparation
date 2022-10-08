string SmallestRotation(string s) {
	int n = SZ(s), i = 0, j = 1;
	s += s;
	while(i < n && j < n) {
		int k = 0;
		while(k < n && s[i + k] == s[j + k]) ++k;
		if(s[i + k] <= s[j + k]) j += k + 1;
		else i += k + 1;
		j += (i == j);
	}
	return s.substr(i < n ? i : j, n);
}
