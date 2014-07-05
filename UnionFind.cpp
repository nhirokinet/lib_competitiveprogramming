class UnionFind {
	private:
		int *parent;
		int *rank;

		int arrsize;
	public:
		UnionFind(int size) {
			this->arrsize = size;
			this->parent = (int *)malloc(sizeof(int) * size);
			this->rank = (int *)malloc(sizeof(int) * size);

			for(int i=0; i<size; i++) {
				parent[i] = i;
				rank[i] = 1;
			}
		}

		~UnionFind() {
			free(parent);
			free(rank);
		}

		bool combine(int id_a, int id_b) {
			id_a = find(id_a);
			id_b = find(id_b);
			if (id_a == id_b) {
				return false;
			}

			if(rank[id_a] > rank[id_b]) {
				parent[id_b] = id_a;
			}

			if(rank[id_a] < rank[id_b]) {
				parent[id_a] = id_b;
			}

			if(rank[id_a] == rank[id_b]){
				parent[id_a] = id_b;
				rank[id_b]++;
			}
			
			return true;
		}

		bool sameGroup(int id_a, int id_b) {
			return find(id_a) == find(id_b);
		}

		int find(int id) {
			if(parent[id] == id)
				return id;
			return parent[id] = find(parent[id]);
		}

		int size() {
			return this->arrsize;
		}
};

