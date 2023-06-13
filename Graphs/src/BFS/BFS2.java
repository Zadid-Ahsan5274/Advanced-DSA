package BFS;

import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class BFS2 {
	private Map<Character, List<Character>> graph;

	public BFS2(Map<Character, List<Character>> graph) {
		this.graph = graph;
	}

	public void traversal(char source) {
		Map<Character, Character> color = new HashMap<>();
		Map<Character, Character> prev = new HashMap<>();
		Map<Character, Integer> distance = new HashMap<>();

		// Initialization
		for (char u : graph.keySet()) {
			if (u != source) {
				color.put(u, 'W');
				prev.put(u, 'N');
				distance.put(u, Integer.MAX_VALUE);
			}
		}

		color.put(source, 'G');
		distance.put(source, 0);

		Queue<Character> queue = new LinkedList<>();
		queue.add(source);

		while (!queue.isEmpty()) {
			char u = queue.remove();

			for (char v : graph.get(u)) {
				if (color.get(v) == 'W') {
					color.put(v, 'G');
					distance.put(v, distance.get(u) + 1);
					prev.put(v, u);
					queue.add(v);
				}
			}

			color.put(u, 'B');
		}

		// Print the results
		System.out.println("Data: color[V], prev[V], d[V]");
		for (char v : graph.keySet()) {
			System.out.println("color[" + v + "] = " + color.get(v));
			System.out.println("prev[" + v + "] = " + prev.get(v));
			System.out.println("d[" + v + "] = " + distance.get(v));
		}
	}

	public static void main(String[] args) {
		Map<Character, List<Character>> adjList = new HashMap<>();
		adjList.put('r', Arrays.asList('v', 's'));
		adjList.put('s', Arrays.asList('r', 'w'));
		adjList.put('t', Arrays.asList('w', 'x', 'u'));
		adjList.put('u', Arrays.asList('t', 'y'));
		adjList.put('v', Arrays.asList('r'));
		adjList.put('w', Arrays.asList('s', 't', 'x'));
		adjList.put('x', Arrays.asList('t', 'u', 'w'));
		adjList.put('y', Arrays.asList('u', 'x'));

		BFS2 bfs = new BFS2(adjList);
		bfs.traversal('s');
	}
}
