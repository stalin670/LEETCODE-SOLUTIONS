class Solution {
public:
    map <int ,int > l;
    int best;
    int node;
    int dfs(int v, bool* visited, vector <int> graph[], int c = 0){
        visited[v] = true;
        int ans = 0;
        for(int i = 0; i < graph[v].size(); i++){
            if(!visited[graph[v][i]])ans = max(ans,dfs(graph[v][i], visited, graph, c+1));
        }
        if(c > best){
             best = c;
            node = v ;
        }
        visited[v] = false;
        return max(c,ans);
    }
    int treeDiameter(vector<vector<int>>& e) {
        int n = e.size();
        vector <int> graph[n+1];
        for(int i = 0; i < n; i++){
            graph[e[i][0]].push_back(e[i][1]);
            graph[e[i][1]].push_back(e[i][0]);
        }
        bool* visited = new bool[n+1]();
        best = 0;
        node = 0;
        dfs(0, visited, graph);
        bool* visited2 = new bool[n+1]();
        return dfs(node, visited2, graph);
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)     {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        int x = (d1 - d1 / 2) + (d2 - d2 / 2);
        return max({d1, d2, x + 1});
    }
};