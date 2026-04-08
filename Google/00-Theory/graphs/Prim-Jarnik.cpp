// 1. Choose a random vertex as the starting point, and include it as the first vertex in the MST.
// 2. Compare the edges going out from the MST. Choose the edge with the lowest weight that connects a vertex among the MST vertices to a vertex outside the MST.
// 3. Add that edge and vertex to the MST.
// 4. Keep doing step 2 and 3 until all vertices belong to the MST.
//
// O(E * log V)
//
//

const int INF = 1000000000;

struct Edge {
    int w = INF, to = -1;

    bool operator < (Edge const &other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

int n;
vector<vector<Edge>> adj;

void prim() {
    int total_weight = 0;

    vector<Edge> min_e(n);
    set<Edge> q;
    vector<bool> selected(n, false);

    min_e[0].w = 0;
    q.insert({0, 0});

    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "No MST!" << endl;
            exit(0);
        }

        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (Edge e : adj[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }

    cout << total_weight << endl;
}
