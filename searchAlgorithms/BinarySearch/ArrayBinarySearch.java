public class ArrayBinarySearch {
	public static void main(String[] args) {
		int[] numberSortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		System.out.println(binarySearch(numberSortedArray, 3));
	}

	public static int binarySearch(int[] numberSortedArray, int key) {
		int firstIndex = 0;
		int lastIndex = numberSortedArray.length - 1;
		int mediumIndex;
		while(firstIndex <= lastIndex) {
			mediumIndex = Math.round((firstIndex + lastIndex) / 2);
			if(key > numberSortedArray[mediumIndex]) {
				firstIndex = mediumIndex + 1;
				continue;
			}
			if(key < numberSortedArray[mediumIndex]) {
				lastIndex = mediumIndex - 1;
				continue;
			}
			return mediumIndex;
 		}
		return -1;
	}
}