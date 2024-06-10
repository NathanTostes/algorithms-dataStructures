public class RecusiveBubbleSort {
	public static void main(String[] args) {
		int[] numbers = {3, 7, 9, 1, 4, 2, 8, 6, 5};
		printArray(numbers);
		sortArray(numbers, numbers.length - 1);
		printArray(numbers);
	}
	
	private static void sortArray(int[] numbers, int positions) {
		if(positions == 1) {
			return;
		}
		int aux;
		for(int i = 0; i < positions; i++) {
			if(numbers[i] > numbers[positions]) {
				aux = numbers[positions];
				numbers[positions] = numbers[i];
				numbers[i] = aux;
			}
		}
		sortArray(numbers, positions - 1);
	}
	
	private static void printArray(int[] array) {
		String string = "[";
		for(int i  = 0; i < array.length - 1; i++) {
			string += array[i] + ", ";
		}
		string += array[array.length - 1] + "]";
		System.out.println(string);
	}
}
