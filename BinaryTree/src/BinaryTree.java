import java.util.TreeMap;

public class BinaryTree {
	public static class Node {
		int data;
		Node left;
		Node right;
		Node(int data, Node l, Node r) {
			this.data = data;
			this.left = l;
			this.right = r;
		}
		
		public int getData() {
			return data;
		}
		
		public Node getLeft() {
			return left;
		}
		
		public Node getRight() {
			return right;
		}
		
		public void setLeft(Node l) {
			left = l;
		}
		
		public void setRight(Node r) {
			right = r;
		}
	}
	
	public BinaryTree() {
	}
	
	public void preOrder(Node root) {
		if (root != null) {
			System.out.println(root.getData());
			preOrder(root.getLeft());
			preOrder(root.getRight());
		}
	} 
}
