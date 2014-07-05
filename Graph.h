class Graph {
	private:
		int mode;
		int graph_size;

		int *graph_map;
		int *weight_map;

		std::vector <std::set <int> > graph_set;

	public:
		static const int MAP = 0;
		static const int SET = 1;

		Graph (int mode, int size) {
			this->graph_size = size;
			this->mode = mode;
			
			if(mode==MAP) {
				graph_map = (int *) calloc(graph_size * graph_size, sizeof(int));
			}

			if(mode==SET) {
				graph_set = *(new std::vector<std::set <int> >(size, *(new std::set<int>())));
			}
		}

		void weighted () {
			if(mode==MAP) {
				weight_map = (int *) calloc(graph_size * graph_size, sizeof(int));
			}

			if(mode==SET) {
				throw "Currently weight graph does not support set implementation.";
			}
		}


		void setWeight (int from, int to, int weight) {
			connect(from, to);

			if(mode==MAP) {
				weight_map[from*graph_size+to] = weight;
			}
		}

		void connect (int from, int to) {
			if(mode==MAP) {
				graph_map[from*graph_size+to] = 1;
			}

			if(mode==SET) {
				graph_set[from].insert(to);
			}

		}

		void bothConnect (int nodea, int nodeb) {
			connect(nodea, nodeb);
			connect(nodeb, nodea);
		}

		bool dfs (int from, int to) {
			int *visited = (int *) calloc(graph_size, sizeof(int));
			return dfs(from, to, visited);
		}
		
		// just set to=-1 to get all connected nodes.
		bool dfs (int from, int to, int *visited) {
			if(visited[from])
				return false;

			if(from==to)
				return true;

			visited[from] = 1;

			bool result = false;

			if(mode==MAP) {
				for(int i=0; i<graph_size; i++) {
					if(graph_map[from*graph_size+i] && from!=i){
						result = result || dfs(i, to, visited);
					}
				}
			}

			if(mode==SET) {
				std::set<int>::iterator it = graph_set[from].begin();

				while(it!=graph_set[from].end() && *it!=from){
					result = result || dfs(*it, to, visited);
					++it;
				}
			}

			return result;
		}

		int bfs (int from, int to) {
			int *visited = (int *) calloc(graph_size, sizeof(int));
			std::queue<int> q;
			int distance = 0;

			if(from==to)
				return 0;

			q.push(from);
			q.push(-1);

			while(!q.empty()) {
				if(q.front() == -1){
					q.pop();
					q.push(-1);
					distance++;
					continue;
				}

				int next = q.front();

				visited[next] = 1;
				q.pop();

				if(mode==MAP) {
					for(int i=0; i<graph_size; i++) {
						if(graph_map[next*graph_size + i] && next!=i && !visited[i]){
							if(i == to)
								return distance+1;

							q.push(i);
							visited[i] = 1;
						}
					}
				}

				if(mode==SET) {
					std::set<int>::iterator it = graph_set[next].begin();

					while(it!=graph_set[next].end()){
						if(graph_map[next*graph_size + *it] && next!=*it && !visited[*it]){
							if(*it == to)
								return distance+1;

							q.push(*it);
							visited[*it] = 1;
						}
					}
				}
			}

			return -1;
		}

		int dijkstra (int from, int to) {
			int *visited = (int *) calloc(graph_size, sizeof(int));
			std::priority_queue<long long> q;

			if(from==to)
				return 0;

			q.push(from);
			visited[from] = 1;

			while(!q.empty()) {
				long long next = q.top();
				long long distance = next>>32;
				next = next & ((1LL<<31)-1LL);

				if(next==to)
					return distance;

				visited[next] = 1;
				q.pop();

				if(mode==MAP) {
					for(int i=0; i<graph_size; i++) {
						if(graph_map[next*graph_size + i] && next!=i && !visited[i]){
							q.push(((distance+weight_map[next*graph_size + i])<<32) | i);
							visited[i] = 1;
						}
					}
				}
			}

			return -1;
		}
};
