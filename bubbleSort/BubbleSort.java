public class BubbleSort {
	public static void main (String[] args) {
		int[] numbers = {4, 2, 7, 9, 1, 3, 5, 8, 6};
		printArrayElements(numbers);
		printArrayElements(numericBubbleSort(numbers));
	}
	
	private static int[] numericBubbleSort(int[] numbers) {
		int swap;
		for(int i = 0; i < numbers.length - 1; i++) {
			for(int j = i + 1; j < numbers.length; j++) {
				if(numbers[j] < numbers[i]) {
					swap = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = swap;
				}
			}
		}
		return numbers;
	}
	
	private static void printArrayElements(int[] array) {
		String string = "[";
		for(int i = 0; i < array.length - 1; i++) {
			string += array[i] + ", ";
		}
		string += array[array.length - 1] + "]";
		System.out.println(string);
	}
}