/**
 * Description: Cycle Detection (Detects a cycle in a directed or undirected graph.) 
 * Usage: O(V) 
 * Source: https://github.com/dragonslayerx 
 */

enum Color {
	gray, white, black
};

bool detectCycle(vector<vector<int> > &G, bool isUndirected)
{
    Color isVisited[MAX] = {white};
    int parent[MAX];
    stack<int> S;
    for (int i = 0;  i < G.size(); i++) {
        if (isVisited[i] == black) continue;
        S.push(i);
        while (!S.empty()) {
            int u = S.top();
            S.pop();
            if (isVisited[u] == gray) {
                isVisited[u] = black;
            } else {
                S.push(u);
                isVisited[u] = gray;
                for (int i = 0; i < G[u].size(); i++) {
                    int v = G[u][i];
                    if (isVisited[v] == white) {
                        parent[v] = u;
                        S.push(v);
                    } else if (isVisited[v] == gray and (!isUndirected or v != parent[u])) {
                        return true;
                    }
                }
            }
        }
    }
}