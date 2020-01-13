
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Recursive rec = new Recursive();
		int a = rec.factorial(4);
		System.out.println("a = " + a);
		int b = rec.fibonacci(3);
		System.out.println("b = " + b);
		long[] c = rec.fibonacciGood(5);
		System.out.println(c[0] + "  " + c[1]);
	}

}
