#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 1001;

class Graph
{
private:
	int numVertices, numEdges;
	set<int> adj[MAXN];
	int degree[MAXN];

	bool used[MAXN];
	int HC[MAXN];
public:
	Graph() {
		fill(degree, degree + MAXN, 0);
		fill(used, used + MAXN, false);
		fill(HC, HC + MAXN, 0);
	}

	void printInfo();
	bool readFile(string fileName);
	bool checkEuler();
	vector<int> eulerCycle(int numVerStart);
	bool checkHamilton();
	void hamiltonCycle(int pos, int u);
};

