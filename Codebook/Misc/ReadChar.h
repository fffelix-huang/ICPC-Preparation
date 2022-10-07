inline char gc() {
	static const int SZ = 1 << 20;
	static int cnt = 1 << 21;
	static char buf[SZ];
	static char *ptr = buf, *end = buf;
	if(ptr == end) {
		if(cnt < SZ) return EOF;
		cnt = fread(buf, 1, SZ, stdin);
		ptr = buf;
		end = buf + cnt;
	}
	return *(ptr++);
}
