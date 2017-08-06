struct Edge { int a, b, c; };
bool operator<(Edge e1, Edge e2) { return e1.c < e2.c; }
OD(Edge) { return os << make_pair(PII(x.a, x.b), x.c); }

class MST {
    V<Edge> edges, mst;
    int n;

    VI lead;
    int find(int x) { return x == lead[x] ? x : lead[x] = find(lead[x]); }
    void onion(int a, int b) { lead[find(a)] = find(b); }
    bool same(int a, int b) { return find(a) == find(b); }

public:
    MST(V<Edge> &edg, int m) : edges(edg), n(m) {
        sort(ALL(edges));
        lead.RS(n);
        REP(i, n)
            lead[i] = i;
        for(Edge e : edges)
            if(!same(e.a, e.b)) {
                mst.EB(e);
                onion(e.a, e.b);
            }
    }

    V<Edge> get_edges() { return mst; }
    VVPII get_G() {
        VVPII G(n);
        for(Edge e : mst) {
            G[e.a].EB(e.b, e.c);
            G[e.b].EB(e.a, e.c);
        }
        return G;
    }
    LL total_cost() {
        LL answ = 0;
        for(Edge e : mst)
            answ += e.c;
        return answ;
    }
};
