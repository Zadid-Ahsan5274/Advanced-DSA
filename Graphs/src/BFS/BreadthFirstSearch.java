package BFS;

import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstSearch {
	private static final int WHITE = 0;
	private static final int GRAY = 1;
	private static final int BLACK = 2;
	private static final int INF = Integer.MAX_VALUE;

	public void BFS(int[][] G, int s) {
		int V = G.length;
		int[] color = new int[V];
		int[] prev = new int[V];
		int[] d = new int[V];

		for (int u = 0; u < V; u++) {
			if (u != s) {
				color[u] = WHITE;
				prev[u] = -1;
				d[u] = INF;
			}
		}

		color[s] = GRAY;
		d[s] = 0;
		prev[s] = -1;

		Queue<Integer> queue = new LinkedList<>();
		queue.add(s);

		while (!queue.isEmpty()) {
			int u = queue.poll();

			for (int v = 0; v < V; v++) {
				if (G[u][v] == 1 && color[v] == WHITE) {
					color[v] = GRAY;
					d[v] = d[u] + 1;
					prev[v] = u;
					queue.add(v);
				}
			}

			color[u] = BLACK;
		}
	}

	public static void main(String[] args) {
		int[][] graph = { { 0, 1, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0, 0 }, { 1, 0, 0, 1, 1, 0 }, { 0, 1, 1, 0, 0, 1 },
				{ 0, 0, 1, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0 } };

		BreadthFirstSearch bfs = new BreadthFirstSearch();
		bfs.BFS(graph, 0);
	}
}
