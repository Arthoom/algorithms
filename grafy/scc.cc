class SCC {
    VVI &G, rev_G;
    int num_of_groups;
    VB vis;

    VI quit_order;
    void quit_order_DFS(int v) {
        vis[v] = 1;
        for(int u : rev_G[v])
            if(!vis[u])
                quit_order_DFS(u);
        quit_order.EB(v);
    }

    VI group;
    void group_DFS(int v, int gr) {
        vis[v] = 1;
        group[v] = gr;
        for(int u : G[v])
            if(!vis[u])
                group_DFS(u, gr);
    }

public:
    SCC(VVI &Graph) : G(Graph) {
        int n = SZ(G);
        rev_G.RS(n);
        REP(v, n)
            for(int u : G[v])
                rev_G[u].EB(v);
        DUMP(rev_G);

        vis.RS(n);
        REP(v, n)
            if(!vis[v])
                quit_order_DFS(v);
        reverse(ALL(quit_order));
        DUMP(quit_order);

        fill(ALL(vis), 0);
        group.RS(n);
        int curr_gr = 0;
        for(int v : quit_order)
            if(!vis[v])
                group_DFS(v, curr_gr++);

        num_of_groups = curr_gr;
    }
    VI get_groups() { return group; }
    int get_num_of_groups() { return num_of_groups; }
    void set(VI &gr, int &num_gr) { gr = group; num_gr = num_of_groups; }
};
