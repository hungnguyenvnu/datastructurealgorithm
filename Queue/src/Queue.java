import SinglyLinkedList.Node;


public class Queue {
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
	public Queue(){}
	
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
	
	public void enqueue(String e) {
		head = new Node(e, head);
		if (isEmpty()){
			tail = head;
		}
		size++;
	}
	
	public void dequeue(){
		Node temp = head;
		while(temp != null) {
			if (temp.getNext() != null){
				temp = temp.getNext();
			}
		}
		size--;
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
