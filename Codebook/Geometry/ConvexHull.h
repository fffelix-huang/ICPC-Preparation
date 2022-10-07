// @return the points of the convex hull in clock-wise order
template<class T>
vector<Point<T>> ConvexHull(vector<Point<T>> points) {
	const int n = SZ(points);
	sort(ALL(points), [](const Point<T>& a, const Point<T>& b) {
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	auto build = [&]() {
		vector<Point<T>> upper;
		upper.PB(points[0]);
		upper.PB(points[1]);
		for(int i = 2; i < n; ++i) {
			while(SZ(upper) >= 2) {
				if(cross(upper.end()[-1] - upper.end()[-2], points[i] - upper.end()[-1]) > 0)
					upper.PPB();
				else break;
			}
			upper.PB(points[i]);
		}
		return upper;
	};
	vector<Point<T>> upper = build();
	reverse(ALL(points));
	vector<Point<T>> lower = build();
	lower.PPB();
	upper.insert(upper.end(), 1 + ALL(lower));
	return upper;
}
