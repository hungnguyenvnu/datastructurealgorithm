public class Stack {
	private static class Node {
		private String element;
		private Node next;
		
		// Constructor
		public Node (String e, Node n) {
			element = e;
			next = n;
		}
		
		public String getElement() {
			return element;
		}
		
		public Node getNext() {
			return next;
		}
		
		public void setNext(Node n) {
			next = n;
		}
	}
	
	private Node head = null;
	private Node tail = null;
	int size = 0;
	public Stack() {}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public String first() {
		if (isEmpty()) {
			return null;
		}
		return head.getElement();
	}
	
	public String last() {
		if (isEmpty()) {
			return null;
		}
		return tail.getElement();
	}
	
	public void push(String e) {
		Node newest = new Node(e, head);
		if (isEmpty()) {
			head = tail = newest;
		} else {
			Node newNext = newest.getNext(); 
			newNext = head;
			head = newest;
		}
		size++;
		return;
	}
	
	public void pop() {
		if (isEmpty()) {
			return;
		}
		head = head.getNext();
		size--;
		if (size == 0) {
			tail = null;
		}
	}

}
