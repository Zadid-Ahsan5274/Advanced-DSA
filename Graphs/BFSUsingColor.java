package BFS;
import java.util.*;

public class BFSUsingColor {
	
	private static final int WHITE = 0;    //Represents an unvisited node
	private static final int GRAY = 1;     //Represents a visited but not explored node
	private static final int BLACK = 2;    //Represents a fully explored node
	
	private int vertices;   //Number of vertices in the graph
	private List<List<Integer>> adjacencyList;  //Adjacency list representation of the graph
	
	public BFSUsingColor(int vertices) {
		this.vertices = vertices;
		adjacencyList = new ArrayList<>(vertices);
		
		//Initializing adjacency list for each vertex
		for(int i = 0; i < vertices; i++) {
			adjacencyList.add(new LinkedList<>());
		}
	}
	
	//Function to add an edge between two vertices
	public void addEdge(int source, int destination) {
		adjacencyList.get(source).add(destination);
		adjacencyList.get(destination).add(source);
	}
	
	//BFS traversal starting from a given source vertex
	public void bfs(int source) {
		int color[] = new int[vertices];
		Arrays.fill(color, WHITE);
		Queue<Integer> queue = new LinkedList<>();
		color[source] = GRAY;
		queue.offer(source);
		
		while(!queue.isEmpty()) {
			int currentVertex = queue.poll();
			System.out.print(currentVertex + " ");
			List<Integer> neighbors = adjacencyList.get(currentVertex);
			for(int neighbor : neighbors) {
				if(color[neighbor] == WHITE) {
					color[neighbor] = GRAY;
					queue.offer(neighbor);
				}
			}
			color[currentVertex] = BLACK;
		}
	}
	
	public static void main(String[] args) {
		BFSUsingColor bfsUC = new BFSUsingColor(6);
		bfsUC.addEdge(0, 1);
		bfsUC.addEdge(0, 2);
		bfsUC.addEdge(1, 3);
		bfsUC.addEdge(2, 4);
		bfsUC.addEdge(2, 5);
		System.out.println("BFS Traversal: ");
		bfsUC.bfs(0);
	}

}
