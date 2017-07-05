//end of templates

struct Point { int x, y; }; //ten caly skompresowany kod to czesc tego co mi wyslales (czesc kodu Malysy)
ostream& operator<<(ostream& os, Point p) { return os << PII{p.x, p.y}; }
bool operator==(Point a, Point b) { return a.x == b.x and a.y == b.y; }
inline Point operator-(Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; }
inline LL operator*(Point a, Point b) { return LL(a.x) * b.y - LL(a.y) * b.x; }
inline bool operator<(Point a, Point b) { return a.x == b.x ? a.y < b.y : a.x < b.x; };

typedef vector<Point> VP;
template<class I> VP gorna_otoczka(I begin, I end, VP up = VP()) {
    FOR(x, begin, --end) {
        while(SZ(up) > 1 && (up.end()[-1] - up.end()[-2]) * (*x - up.end()[-2]) > 0)
        	up.pop_back();
        up.EB(*x);
    }
    return up;
}

int main() {
	int n;
	cin >> n;
	VP v(n);
	for(auto &p : v)
	    cin >> p.x >> p.y;
	sort(ALL(v));
	LOGN(v);

	VP up = gorna_otoczka(ALL(v)), all = gorna_otoczka(ALLR(v), VP(next(up.begin()), prev(up.end())));
	DUMP(all);
}