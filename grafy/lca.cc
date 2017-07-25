class LCA {
    VI lead, res;
    VB vis;
    VVI &G, req_in_node;
    VPII &req;

    int find(int a) { return a == lead[a] ? a : lead[a] = find(lead[a]); }
    void onion(int a, int b) /*onion a into b*/ { lead[find(a)] = find(b); }
    int nd_node(int id, int v) { return req[id].ST == v ? req[id].ND : req[id].ST; }

    void DFS(int v = 0) {
        vis[v] = 1;
        VI &r = req_in_node[v];
        REP(i, SZ(r)) {
            int nd = nd_node(r[i], v);
            if(vis[nd])
                res[r[i]] = find(nd);
        }
        for(int u : G[v])
            if(!vis[u]) {
                DFS(u);
                onion(u, v);
            }
    }

public:
    LCA(VVI &Graph, VPII &Requests) : G(Graph), req(Requests) {
        res.RS(SZ(req));
        req_in_node.RS(SZ(G));
        vis.RS(SZ(G));
        lead.RS(SZ(G));
        REP(i, SZ(lead))
            lead[i] = i;
        REP(i, SZ(req)) {
            req_in_node[req[i].ST].EB(i);
            req_in_node[req[i].ND].EB(i);
        }
        DFS();
    }
    
    VI get_results() { return res; }
};
