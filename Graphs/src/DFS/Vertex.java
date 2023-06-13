package DFS;

import java.util.ArrayList;
import java.util.List;

public class Vertex {

	private String name;
	private boolean visited;
	private List<Vertex> adjacencyList;
	private Vertex predecessor;

	public Vertex(String name) {
		this.name = name;
		this.adjacencyList = new ArrayList<Vertex>();
	}

	public void addNeighbor(Vertex vertex) {
		this.adjacencyList.add(vertex);
	}

	public boolean isVisited() {
		return visited;
	}

	public void setVisited(boolean visited) {
		this.visited = visited;
	}

	public Vertex getPredecessor() {
		return predecessor;
	}

	public void setPredecessor(Vertex predecessor) {
		this.predecessor = predecessor;
	}

	public List<Vertex> getAdjacenciesList() {
		return adjacencyList;
	}

	@Override
	public String toString() {
		return this.name;
	}

}
