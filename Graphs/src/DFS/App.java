package DFS;

public class App {

	public static void main(String[] args) {
		Vertex vertexA = new Vertex("A");
		Vertex vertexB = new Vertex("B");
		Vertex vertexC = new Vertex("C");
		Vertex vertexD = new Vertex("D");
		Vertex vertexE = new Vertex("E");

		vertexA.addNeighbor(vertexB);
		vertexA.addNeighbor(vertexC);

		vertexB.addNeighbor(vertexD);
		vertexB.addNeighbor(vertexE);

		vertexC.addNeighbor(vertexE);
		vertexC.addNeighbor(vertexB);

		DFS dfs = new DFS();
		dfs.DFS(vertexE);
	}

}
