
public class SinglyLinkedList {
	private static class Node {
		private String element;
		private Node next;
		
		Node(String e, Node n) {
			element = e;
			next = n;
		}
		
		public String getElement() {
			return element;
		}
		public Node getNext() {
			return next;
		}
		
		public void setNext(Node n){
			next = n;
		}
	}
	
	private Node head = null;
	private Node tail = null;
	int size = 0;
	public SinglyLinkedList(){
		
	}
	
	public int size(){
		return size;
	}
	
	public boolean isEmpty(){
		return (size == 0);
	}
	
	public String first() {
		if (isEmpty())
			return null;
		return head.getElement();
	}
	
	public String last() {
		if (isEmpty())
			return null;
		return tail.getElement();
	}
	
	public void addFirst(String e) {
		head = new Node(e, head);
		if (isEmpty()){
			tail = head;
		}
		size++;
	}
	
	public void addLast(String e){
		Node newest = new Node(e, null);
		if (isEmpty()){
			head = newest;
		} else {
			tail.setNext(newest);
		}
		tail = newest;
		size++;
	}
	
	public void removeFirst() {
		if (isEmpty()) return;
		head = head.getNext();
		size--;
		if (size == 0)
			tail = null;
		return;
	}
}
