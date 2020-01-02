
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack stack = new Stack();
		stack.push("Hung");
		stack.push("Van");
		stack.push("Nguyen");
		
		stack.pop();
		
		System.out.println(stack.first());
		System.out.println(stack.last());
	}

}
