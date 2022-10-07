struct HLD : LCA {
public:
	using LCA::add_edge;
	using LCA::build;
	using LCA::dist;
	using LCA::get_diameter;
	using LCA::kth_ancestor;
	using LCA::kth_node_on_path;
	using LCA::lca;

	HLD() : HLD(0) {}
	HLD(int _n) : LCA(_n) {}

	inline int get(int u) const { return tour_start[u]; }

	// return $\text{path}_{[u, \dots , p)}$ where $p$ is an ancestor of $u$
	vector<pii> path_up(int u, int p) const {
		vector<pii> seg;
		while(heavy_root[u] != heavy_root[p]) {
			seg.EB(get(heavy_root[u]), get(u) + 1);
			u = parent[heavy_root[u]];
		}
		// $id_p$ is smaller than $id_u$ but we don't want $id_p$
		seg.EB(get(p) + 1, get(u) + 1);
		return seg;
	}

	vector<pii> path(int u, int v) const {
		int z = lca(u, v);
		auto lhs = path_up(u, z);
		auto rhs = path_up(v, z);
		lhs.EB(get(z), get(z) + 1);
		lhs.insert(lhs.end(), ALL(rhs));
		return lhs;
	}
};
