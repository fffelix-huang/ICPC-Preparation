int sign(const double& a) { return fabs(a) < EPS ? 0 : a > 0 ? 1 : -1; }
template<class T>
int ori(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
	return sign(cross(b - a, c - a));
}
template<class T>
bool collinearity(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
	return sign(cross(a - c, b - c)) == 0;
}
template<class T>
bool btw(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
	if(!collinearity(a, b, c)) return 0;
	return sign(dot(a - c, b - c)) <= 0;
}
template<class T>
bool seg_intersect(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d) {
	int abc = ori(a, b, c), abd = ori(a, b, d);
	int cda = ori(c, d, a), cdb = ori(c, d, b);
	if(abc == 0 && abd == 0) return btw(a, b, c) || btw(a, b, d) || btw(c, d, a) || btw(c, d, b);
	return abc * abd <= 0 && cda * cdb <= 0;
}
template<class T>
Point<T> intersect(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d) {
	T a123 = cross(b - a, c - a);
	T a124 = cross(b - a, d - a);
	return (d * a123 - c * a124) / (a123 - a124);
}