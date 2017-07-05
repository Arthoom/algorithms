//end of templates

struct GrafPodslow {
    V< map<char,int> > edges = {map<char,int>()};
    VI link = {-1}, length = {0};
    int last = 0;

    GrafPodslow(string s) {
        REP(i, SZ(s)) {
            edges.EB(map<char,int>());
            length.EB(i+1);
            link.EB(0);
            int r = SZ(edges) - 1, p = last;
            while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
                edges[p][s[i]] = r;
                p = link[p];
            }
            if(p != -1) {
                int q = edges[p][s[i]];
                if(length[p] + 1 == length[q])
                    link[r] = q;
                else {
                    edges.EB(edges[q]);
                    length.EB(length[p] + 1);
                    link.EB(link[q]);
                    int q_prim = edges.size()-1;
                    link[q] = q_prim;
                    link[r] = q_prim;
                    while(p >= 0 && edges[p][s[i]] == q)
                    {
                        edges[p][s[i]] = q_prim;
                        p = link[p];
                    }
                }
            }
            last = r;
        }
    }
};

int main() {
    string s;
    cin >> s;
    GrafPodslow ga(s);
    DUMP(ga.edges);
}
