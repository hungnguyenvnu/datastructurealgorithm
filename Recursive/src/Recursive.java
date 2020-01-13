
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
	
	public int linearSum(int[] data, int n) {
		if (n == 0)
			return 0;
		else
			return linearSum(data, n-1) + data[n-1];
	}
	
	// Fibonacci 
	public int fibonacci(int n) {
		if (n <= 1)
			return n;
		else
			return fibonacci(n-2) + fibonacci(n-1);
	}
	
	// Fibonacci with O(n)
	public long[] fibonacciGood(int n) {
		if (n <= 1) {
			long[] answer = {n, 0};
			return answer;
		} else {
			long[] temp = fibonacciGood(n - 1);
			long[] answer = {temp[0] + temp[1], temp[0]};
			return answer;
		}
	}
	
	public void reverseArray(int data[], int low, int high) {
		if (low < high){ 
			int temp = data[low];
			data[low] = data[high];
			data[high] = temp;
			reverseArray(data, low + 1, high - 1);
		}
	}
}
