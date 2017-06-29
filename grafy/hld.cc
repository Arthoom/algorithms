//end of templates

VVI G; //zawiera synow i ojca (bez ojca latwiej)
VI parent;

VVI hld = {{}};
VI hld_group, hld_group_pos;
VI sum_subtree;

int sum_subtree_DFS(int v = 0) {
    int sum = 1;
    for(int u : G[v])
        if(u != parent[v])
            sum += sum_subtree_DFS(u);
    return sum_subtree[v] = sum;
}

void hld_DFS(int v = 0, int group = 0) {
    hld_group[v] = group;
    hld[group].EB(v);

    PII max_sum = {-1, -1}; // {sum, vertex}
    for(int u : G[v])
        if(u != parent[v] && sum_subtree[u] > max_sum.ST)
            max_sum = { sum_subtree[u], u };

    for(int u : G[v])
        if(u != parent[v]) {
            if(u == max_sum.ND)
                hld_group_pos[u] = hld_group_pos[v] + 1, hld_DFS(u, group);
            else
                hld.EB(VI()), hld_DFS(u, SZ(hld)-1);
        }
}

void do_stuff(int group, int from /*(to = 0)*/) {
    LOG(group); LOGN(from);
}

void go_to_root(int v) {
    while(v != -1) {
        do_stuff(hld_group[v], hld_group_pos[v]);
        v = parent[ hld[ hld_group[v] ][0] ];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    G.RS(n);
    parent.RS(n);

    REP(i, n-1) {
        int a, b;
        cin >> a >> b;
        parent[--b] = --a;
        G[a].EB(b);
        G[b].EB(a);
    }
    DUMP(G);
    DUMP(parent);
    parent[0] = -1;

    sum_subtree.RS(n);
    sum_subtree_DFS();
    DUMP(sum_subtree);

    hld_group.RS(n);
    hld_group_pos.RS(n);
    hld_DFS();
    DUMP(hld);
    DUMP(hld_group);
    DUMP(hld_group_pos);

    int q;
    cin >> q;
    while(q--) {
        int a;
        cin >> a;
        LOGN(a);
        go_to_root(--a);
    }

    return 0;
}