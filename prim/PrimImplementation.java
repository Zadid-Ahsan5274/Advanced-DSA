package prim;

public class PrimImplementation {

	public static void main(String[] args) {
		// graph nodes -> a, b, c, d, e, f, z
		// a = 0 || b = 1 || c = 2 || d = 3 || e = 4 || f = 5 || z = 6
		/*
		 * a to b -> weight 4 a to c -> weight 3 b to f -> weight 5 b to e -> weight 12
		 * f to z -> weight 16 c to e -> weight 10 c to d -> weight 7 e to z -> weight 5
		 * d to e -> weight 2
		 */
		int graph[][] = new int[][] { { 0, 4, 3, 0, 0, 0, 0 }, { 4, 0, 0, 0, 12, 5, 0 }, { 3, 0, 0, 0, 7, 10, 0, 0 },
				{ 0, 0, 7, 0, 2, 0, 0 }, { 0, 0, 10, 2, 0, 0, 5 }, { 0, 5, 0, 0, 0, 0, 16 }, { 0, 0, 0, 0, 5, 16, 0 } };
		int visited[] = new int[7];
		int min = Integer.MAX_VALUE;
		int source_vertex = 0;
		int dest_vertex = 0;
		int total = 0;

		for (int i = 0; i < 7; i++) {
			visited[i] = 0;
			for (int j = 0; j < 7; j++) {
				if (graph[i][j] == 0) {
					graph[i][j] = min;
				}
			}
		}
		visited[0] = 1;
		for (int counter = 0; counter < 6; counter++) {
			min = Integer.MAX_VALUE;
			for (int i = 0; i < 7; i++) {
				if (visited[i] == 1) {
					for (int j = 0; j < 7; j++) {
						if (visited[j] == 0) {
							if (min > graph[i][j]) {
								min = graph[i][j];
								source_vertex = i;
								dest_vertex = j;
							}
						}
					}
				}
			}
			visited[dest_vertex] = 1;
			total = total + min;
			System.out.println("source " + source_vertex + " --> destination " + dest_vertex + " : " + min);

		}
		System.out.println("Total weight of the graph = " + total);
	}

}
