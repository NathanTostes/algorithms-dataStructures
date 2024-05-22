public class BidimentionalArrays {
	public static void main(String[] args) {
		int[][] mainArray = new int[10][];
		int count = 0;
		for(int i = 0; i < mainArray.length; i++) {
			int[] temporaryArray = new int[i + 1];
			for(int j = 0; j < temporaryArray.length; j++){
				temporaryArray[j] = count;
				count++;
			}
			mainArray[i] = temporaryArray;
		}
		showBidimentionalArray(mainArray);
	}
	public static void showBidimentionalArray(int[][] array) {
		for(int i = 0; i < array.length; i++) {
			for(int j = 0; j < array[i].length; j++) {
				System.out.print(array[i][j] + " ");
			}
			System.out.println("\n");
		}
	}
}
