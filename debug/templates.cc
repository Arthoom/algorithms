#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for (decltype(a) i = (a), i##__ = (n); i <= i##__; ++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,n) for (decltype(n) i = (a), i##__ = (n); i >= i##__; --i)
#define REPD(i,n) FORD(i,(n)-1,0)
#define ALL(x) x.begin(), x.end()
#define ALLR(x) x.rbegin(), x.rend()
#define EB emplace_back
#define ST first
#define ND second
#define OS ostream
#define OO(A) template<class... T> OS& operator<<(OS& os, const A<T...>& x) { return __o(os, ALL(x)); }
#define OD(...) OS& operator<<(OS &os, const __VA_ARGS__ &x)
#define SZ(x) ((int)x.size())
#define RS resize
#define V vector
#define nl '\n'

typedef long long LL;
typedef pair<int, int> PII;
typedef V<int> VI;
typedef V<VI> VVI;
typedef V<PII> VPII;
typedef V<VPII> VVPII;
typedef V<bool> VB;
typedef V<VB> VVB;

template<class I> OS& __o(OS&, I, I);
template<class T, size_t N> OD(array<T, N>) { return __o(os, ALL(x)); }
OO(vector) OO(deque) OO(set) OO(multiset) OO(map) OO(multimap)
template<class A, class B> OD(pair<A, B>) {
    return os << "(" << x.ST << ", " << x.ND << ")";
}
template<class I> OS& __o(OS& os, I a, I b) {
    os << "{ ";
    for (; a != b;)
        os << *a++, os << " ";
    return os << "}";
}
template<class I> OS& __d(OS& os, I a, I b) {
    os << "{\n";
    for (I c = a; a != b; ++a)
        os << "  " << distance(c, a) << ": " << *a << endl;
    return os << "}";
}
template<class... T> void __e(T&&... a) {
    int t[] = {(cerr << forward<T>(a), 0)...}; (void)t;
    cerr << endl;
}

template<class A, class B> inline void mini(A& a, B&& b) { if (b < a) a = b; }
template<class A, class B> inline void maxi(A& a, B&& b) { if (b > a) a = b; }

inline int pow2(int n) { return sizeof(int) * 8 - __builtin_clz(n); }

#ifdef DEBUG
# define D(...) __VA_ARGS__
#else
# define D(...)
#endif

#define LOG(x) D(cerr << #x ": " << x << "  ")
#define LOGN(x) D(LOG(x) << endl)
#define DUMP(x) D(cerr << #x ": ", __d(cerr, ALL(x)) << endl)
#define E(...) D(__e(__VA_ARGS__))

//end of templates

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}