#include "Graph.h"

void Graph::printInfo()
{
    cout << "Info of graph: " << endl;
    cout << "Vertices = " << numVertices << ", " << "Edges = " << numEdges << endl;

    for (int i = 1; i <= numVertices; i++) {
        if (!adj[i].empty()) {
            cout << "Degree " << i << ": " << degree[i] << endl;
            cout << "Ver " << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

bool Graph::readFile(string fileName)
{
    ifstream file(fileName);

    if (!file.is_open()) {
        return false;
    }

    string line;
    int u, v;
    int vertices, edges;

    if (getline(file, line)) {
        sscanf_s(line.c_str(), "%d %d", &vertices, &edges);
        this->numVertices = vertices;
        this->numEdges = edges;
    }
    else {
        file.close();
        return false;
    }

    while (getline(file, line)) {
        sscanf_s(line.c_str(), "%d %d", &u, &v);

        adj[u].insert(v);
        adj[v].insert(u);

        degree[u]++;
        degree[v]++;
    }

    file.close();
    return true;
}

bool Graph::checkEuler()
{
    for (int i = 1; i <= numVertices; i++) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

vector<int> Graph::eulerCycle(int numVerStart)
{
    stack<int> st;
    vector<int> EC;

    st.push(numVerStart);
    while (!st.empty()) {
        int x = st.top();
        if (adj[x].size() != 0) {
            int y = *adj[x].begin();
            st.push(y);

            // delete (x, y)
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else {
            st.pop();
            EC.push_back(x);
        }
    }
    return EC;
}

bool Graph::checkHamilton()
{
    for (int i = 1; i < numVertices; i++) {
        if (degree[i] < numVertices / 2) return false;
    }

    return true;
}

void Graph::hamiltonCycle(int pos, int u)
{
    used[u] = true;
    HC[pos] = u;

    if (pos == numVertices) {
        if (adj[u].find(HC[1]) != adj[u].end()) {
            HC[pos + 1] = HC[1];
            for (int k = 1; k <= pos + 1; k++) {
                cout << HC[k] << " ";
            }
            cout << endl;
        }
        used[u] = false;
        return;
    }

    for (int v : adj[u]) {
        if (!used[v]) {
            this->hamiltonCycle(pos + 1, v);
        }
    }

    used[u] = false;
}
