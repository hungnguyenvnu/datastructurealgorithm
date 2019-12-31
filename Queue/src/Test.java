
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue queue = new Queue();
		queue.enqueue("Hung");
		queue.enqueue("Van");
		queue.enqueue("Nguyen");
		queue.enqueue("4545");
		queue.enqueue("65sfgs");
		queue.enqueue("asedrsg5");
		queue.dequeue();
		
		//print queue
		System.out.println(queue.last());
		System.out.println(queue.first());
	}

}
