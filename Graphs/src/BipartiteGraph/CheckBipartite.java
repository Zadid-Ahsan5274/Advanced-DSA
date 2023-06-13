package BipartiteGraph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class CheckBipartite {
	private int numVertices;
	private List<List<Integer>> adjacencyList;

	public CheckBipartite(int numVertices) {
		this.numVertices = numVertices;
		adjacencyList = new ArrayList<>(numVertices);
		for (int i = 0; i < numVertices; i++) {
			adjacencyList.add(new ArrayList<>());
		}
	}

	public void addEdge(int u, int v) {
		adjacencyList.get(u).add(v);
		adjacencyList.get(v).add(u);
	}

	public boolean isBipartite() {
		int[] colors = new int[numVertices];
		for (int i = 0; i < numVertices; i++) {
			colors[i] = -1; // Initialize all vertices with no color
		}

		for (int i = 0; i < numVertices; i++) {
			if (colors[i] == -1) {
				if (!isBipartiteBFS(i, colors)) {
					return false;
				}
			}
		}
		return true;
	}

	private boolean isBipartiteBFS(int startVertex, int[] colors) {
		Queue<Integer> queue = new LinkedList<>();
		queue.add(startVertex);
		colors[startVertex] = 1; // Color the starting vertex

		while (!queue.isEmpty()) {
			int vertex = queue.poll();

			for (int neighbor : adjacencyList.get(vertex)) {
				if (colors[neighbor] == -1) {
					colors[neighbor] = 1 - colors[vertex]; // Assign alternate color to the neighbor
					queue.add(neighbor);
				} else if (colors[neighbor] == colors[vertex]) {
					return false; // Neighbor and vertex have the same color, not bipartite
				}
			}
		}
		return true;
	}

	public static void main(String[] args) {
		// Create a bipartite graph with 6 vertices
		CheckBipartite graph = new CheckBipartite(6);

		// Add edges to the graph
		graph.addEdge(0, 1);
		graph.addEdge(0, 3);
		graph.addEdge(1, 2);
		graph.addEdge(2, 3);
		graph.addEdge(3, 4);
		graph.addEdge(4, 5);

		// Check if the graph is bipartite
		boolean isBipartite = graph.isBipartite();
		System.out.println("Is the graph bipartite? " + isBipartite);
	}
}
