struct Halfplane { 
	Point p, pq; 
	ld angle;
	Halfplane() {}
	Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
		angle = atan2l(pq.y, pq.x);
	}
	bool out(const Point& r) { return cross(pq, r - p) < -EPS; }
	bool operator<(const Halfplane& e) const { return angle < e.angle; }
	friend Point inter(const Halfplane& s, const Halfplane& t) {
		ld alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
		return s.p + (s.pq * alpha);
	}
};
vector<Point> hp_intersect(vector<Halfplane>& H) { 
	Point box[4] = {
		Point(inf, inf), Point(-inf, inf),
		Point(-inf, -inf), Point(inf, -inf)
	};
	for(int i = 0; i < 4; ++i) H.EB(box[i], box[(i + 1) % 4]);
	sort(H.begin(), H.end());
	deque<Halfplane> dq;
	int len = 0;
	for(int i = 0; i < SZ(H); i++) {
		while(len > 1 && H[i].out(inter(dq[len - 1], dq[len - 2]))) {
			dq.PPB(); --len;
		}
		while(len > 1 && H[i].out(inter(dq[0], dq[1]))) {
			dq.pop_front(); --len;
		}
		if(len > 0 && fabsl(cross(H[i].pq, dq[len-1].pq)) < EPS) {
			if(dot(H[i].pq, dq[len - 1].pq) < 0.0) return {};
			if(H[i].out(dq[len - 1].p)) {
				dq.PPB(); --len;
			} else continue;
		}
		dq.PB(H[i]);
		++len;
	}
	while(len > 2 && dq[0].out(inter(dq[len - 1], dq[len - 2]))) {
		dq.PPB(); --len;
	}
	while(len > 2 && dq[len - 1].out(inter(dq[0], dq[1]))) {
		dq.pop_front(); --len;
	}
	if(len < 3) return {};
	vector<Point> ret(len);
	for(int i = 0; i + 1 < len; ++i) ret[i] = inter(dq[i], dq[i+1]);
	ret.back() = inter(dq[len-1], dq[0]);
	return ret;
}
