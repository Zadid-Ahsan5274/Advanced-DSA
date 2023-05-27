public class PostOrderTraversal {

	TreeNode root;

	private class TreeNode {
		private TreeNode left;
		private TreeNode right;
		private char data;

		public TreeNode(char data) {
			this.data = data;
		}
	}

	public void createBinaryTree() {
		TreeNode first = new TreeNode('A'); // creating nodes
		TreeNode second = new TreeNode('B');
		TreeNode third = new TreeNode('C');
		TreeNode fourth = new TreeNode('D');
		TreeNode fifth = new TreeNode('E');
		TreeNode sixth = new TreeNode('F');
		TreeNode seventh = new TreeNode('G');
		TreeNode eighth = new TreeNode('H');
		TreeNode nineth = new TreeNode('I');
		TreeNode tenth = new TreeNode('J');

		root = first; // setting root as first node
		first.left = second; // setting second treenode as left child of root
		first.right = third; // setting third treenode as right child of root

		second.left = fourth;
		second.right = fifth;

		third.left = sixth;
		third.right = seventh;

		fourth.right = eighth;
		sixth.left = nineth;
		sixth.right = tenth;

	}

	public void postOrder(TreeNode root) {
		if (root == null) {
			return;
		}
		postOrder(root.left);
		postOrder(root.right);
		System.out.print(root.data + " ");
	}

	public static void main(String[] args) {
		PostOrderTraversal bt = new PostOrderTraversal();
		bt.createBinaryTree();
		System.out.print("postorder traversal is: ");
		bt.postOrder(bt.root);
	}

}
