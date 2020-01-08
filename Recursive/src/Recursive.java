
public class Recursive {
	// Factorial
	public int factorial (int n) throws IllegalArgumentException {
		if (n < 0)
			throw new IllegalArgumentException();
		else if (n == 0)
			return 1;
		else
			return n * factorial(n - 1);
		
	}
	
	public int linearSum(int[ ] data, int n) {
		if (n == 0)
			return 0;
		else
			return linearSum(data, n−1) + data[n−1];
	}
}
