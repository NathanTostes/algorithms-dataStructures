public class ArrayLinearSearch {
	public static void main(String[] args) {
		int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		linearSearch(numbers, 3);
	}

	public static void linearSearch(int[] sortedNumbersArray, int key) {
		for(int i = 0; i < sortedNumbersArray.length; i++) {
			if(sortedNumbersArray[i] == key) {
				System.out.println(i);
				return;
			}
		}
		System.out.println("Number not found");
	}
}
