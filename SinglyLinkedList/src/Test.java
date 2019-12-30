
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SinglyLinkedList linkedList = new SinglyLinkedList();
		linkedList.addFirst("Hung");
		linkedList.addFirst("Van");
		linkedList.addFirst("Nguyen");
		
		System.out.println(linkedList.first());
		
		linkedList.removeFirst();
		System.out.println(linkedList.first());
		
	}

}
