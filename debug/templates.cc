#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for (decltype(n) i = (a), i##__ = (n); i <= i##__; ++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,n) for (decltype(a) i = (a), i##__ = (n); i >= i##__; --i)
#define REPD(i,n) FORD(i,(n)-1,0)
#define ALL(x) x.begin(), x.end()
#define EB emplace_back
#define ST first
#define ND second
#define SZ(x) ((int)x.size())
#define RS resize
#define V vector
constexpr char nl = '\n';
template<class T, class B> void mini(T &&a, B &&b) { if (b < a) a = b; }
template<class T, class B> void maxi(T &&a, B &&b) { if (b > a) a = b; }
int pow2(int x) { return x < 2 ? 0 : sizeof(x) * 8 - __builtin_clz(x - 1); }

#define NSTR(a...) typename enable_if<!is_same<string, typename remove_reference<T>::type>::value, a>::type()
#define TMP(func, a...) template<class T> auto func(T &&x) -> decltype(a)
template<class T> struct Off { T __a, __b; };
TMP(O, NSTR(Off<decltype(x.begin())>)) { return {x.begin(), x.end()}; }
TMP(O, cerr << x, x) { return x; }
TMP(O, x.first, x) { return x; }
#define OP operator<<
#define TH *this
struct Debug {
    ~Debug() { cerr << nl; }
    Debug& operator()(int x = 0) { REP(a, x+1) cout << "  "; return TH; }
    TMP(OP, cerr << x, TH) { cerr << O(x); return TH; }
    TMP(OP, x.begin(), NSTR(int), TH) {
        cerr <<  "{\n";
        for (auto a = x.begin(); a != x.end(); ++a)
            TH << "  " << distance(x.begin(), a) << ": " << O(*a) << '\n';
        return TH << "}";
    }
    TMP(OP, x.first, TH) { return TH << "(" << O(x.first) << ", " << O(x.second) << ")"; }
    TMP(OP, x.__a, TH) {
        cerr << "{";
        for (auto a = x.__a, b = x.__b; a != b; ++a)
            TH << O(*a) << (next(a) == b ? "" : ", ");
        return TH << "}";
    }
};
struct DebugOff { 
    template<class T> DebugOff& operator<<(T&&) { return TH; }
    DebugOff& operator()(int = 0) { return TH; }
};
#ifdef DEBUG
# define D Debug()
# define DD(a...) a
#else
# define D DebugOff()
# define DD(...)
#endif
#define I(a...) #a ": " << a << "   "
#define TD(T, a...) Debug& operator<<(Debug &d, T &x) { a; return d; }

using VI    = V<int>;
using VVI   = V<VI>;
using LL    = long long;
using VLL   = V<LL>;
using PII   = pair<int, int>;
using VPII  = V<PII>;
using VVPII = V<VPII>;
using VB    = V<bool>;

//end of templates

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
}
