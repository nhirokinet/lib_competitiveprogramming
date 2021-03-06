#include <iostream>
#include <vector>
#include <set>
#include <queue>

#include "UnionFind.h"
#include "LargeInt.h"
#include "Graph.h"

#include "functions.h"

using namespace std;


/*
   For testing this code
   */
#define MOD 1000000007

int main(){
	cout << "MOD = " << MOD << endl;
	cout << "mod_inverse (2, MOD) = " << LargeInt::mod_inverse(2, MOD) << endl;
	cout << "mod_inverse (3, MOD) = " << LargeInt::mod_inverse(3, MOD) << endl;
	cout << "mod_pow (2, 13, MOD) = " << LargeInt::mod_pow(2, 13, MOD) << endl;
	cout << "mod_pow (2, 128, MOD) = " << LargeInt::mod_pow(2, 128, MOD) << endl;
	cout << "mod_nck (5, 2, MOD) = " << LargeInt::mod_nck(5, 2, MOD) << endl;
	cout << "mod_nck (6, 3, MOD) = " << LargeInt::mod_nck(6, 3, MOD) << endl;
	cout << "mod_nck (100, 50, MOD) = " << LargeInt::mod_nck(100, 50, MOD) << endl;

	vector <int> keys, values;

	keys.push_back(1);
	keys.push_back(2);
	keys.push_back(3);
	keys.push_back(4);

	values.push_back(4);
	values.push_back(4);
	values.push_back(1);
	values.push_back(2);

	sort_two_arrays(keys, values);

	for(int i=0; i<keys.size(); i++)
		cout << "sort:\t" << keys[i] << "\t" << values[i] << endl;

	for(int m=1; m<=12; m++)
		cout << "Julian day of 2012/" << m << "/1: " << julianday(2012, m, 1) << endl; 

	UnionFind uf(100);

	uf.combine(1,2);
	uf.combine(2,3);
	uf.combine(0,4);

	cout << uf.sameGroup(1,4) << endl;
	cout << uf.sameGroup(1,3) << endl;
	cout << uf.combine(0,5) << endl;
	cout << uf.combine(0,5) << endl;
	cout << uf.size() << endl;

	cout << "g" << endl;

	Graph g(Graph::MAP, 5);
	g.bothConnect(0,1);
	g.bothConnect(2,1);
	g.bothConnect(3,4);

	cout << g.dfs(0,2) << endl;
	cout << g.dfs(0,3) << endl;
	cout << g.bfs(0,2) << endl;

	cout << "g2" << endl;

	Graph g2(Graph::SET, 5);
	g2.bothConnect(0,1);
	g2.bothConnect(2,1);
	g2.bothConnect(3,4);

	cout << g2.dfs(0,2) << endl;
	cout << g2.dfs(0,3) << endl;
	cout << g2.bfs(0,2) << endl;

	cout << "wg" << endl;

	Graph wg(Graph::MAP, 5);
	wg.weighted();
	wg.setWeight(0,1,2);
	wg.setWeight(1,2,4);
	wg.setWeight(2,1,3);
	wg.setWeight(3,4,3);
	wg.setWeight(4,3,3);

	cout << wg.dijkstra(0,2) << endl;
	cout << wg.dijkstra(0,3) << endl;

}

