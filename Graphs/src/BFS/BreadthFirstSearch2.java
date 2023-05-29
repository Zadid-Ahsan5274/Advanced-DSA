package BFS;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Graph {
	ArrayList<ArrayList<Integer>> graph;
	int V;

	Graph(int nodes) {
		V = nodes;
		graph = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < V; i++) {
			graph.add(new ArrayList<Integer>());
		}
	}

	void addEdge(int v, int u) {
		graph.get(u).add(v);
		graph.get(v).add(u);
	}

	void printGraph() {
		for (int i = 0; i < V; i++) {
			System.out.print("Node " + i);
			for (int x : graph.get(i)) {
				System.out.println(" -> " + x);
				System.out.println();
			}
		}
	}

	void BFS(int source) {
		boolean visited[] = new boolean[V];
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(source);
		System.out.print("BFS Traversal: ");
		visited[source] = true;
		while (q.isEmpty() == false) {
			int node = q.poll();
			System.out.print(node + " ");
			for (int x : graph.get(node)) {
				if (visited[x] == false) {
					visited[x] = true;
					q.add(x);
				}
			}

		}
	}
}

public class BreadthFirstSearch2 {
	public static void main(String[] args) {
		Graph g = new Graph(5);
		g.addEdge(0, 1);
		g.addEdge(3, 2);
		g.addEdge(2, 4);
		g.addEdge(1, 4);
		g.addEdge(3, 1);
		g.addEdge(2, 0);
		g.printGraph();
		// System.out.println();
		g.BFS(0);
	}
}
