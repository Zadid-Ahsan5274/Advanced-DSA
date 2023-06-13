package DFS;

import java.util.ArrayList;
import java.util.List;

class Graph {
	private int V; // Number of vertices
	private List<Integer>[] adj; // Adjacency list

	Graph(int v) {
		V = v;
		adj = new ArrayList[V];
		for (int i = 0; i < V; i++) {
			adj[i] = new ArrayList<>();
		}
	}

	void addEdge(int u, int v) {
		adj[u].add(v);
	}

	void DFS(int startVertex) {
		boolean[] visited = new boolean[V];
		DFSUtil(startVertex, visited);
	}

	void DFSUtil(int v, boolean[] visited) {
		visited[v] = true;
		System.out.print(v + " ");

		for (int neighbor : adj[v]) {
			if (!visited[neighbor]) {
				DFSUtil(neighbor, visited);
			}
		}
	}
}

public class DepthFirstSearch {
	public static void main(String[] args) {
		int V = 5; // Number of vertices
		Graph graph = new Graph(V);
		graph.addEdge(0, 1);
		graph.addEdge(0, 2);
		graph.addEdge(1, 3);
		graph.addEdge(2, 4);

		System.out.print("Depth-First Traversal (starting from vertex 0): ");
		graph.DFS(0);
	}
}
