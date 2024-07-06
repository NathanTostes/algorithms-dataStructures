import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arrayNumbers = {8, 4, 1, 9, 7, 3, 6, 2, 5};
        System.out.println("---Before Sort---");
        Arrays.stream(arrayNumbers).forEach(value -> System.out.print(value + " "));
        bubbleSort(arrayNumbers);
        System.out.println("\n---After Sort---");
        Arrays.stream(arrayNumbers).forEach(value -> System.out.print(value +  " "));
    }

    private static void bubbleSort(int[] numbers) {
        int swap;
        for(int i = 0; i < numbers.length - 1; i++) {
            for(int j = 0; j < numbers.length - i - 1; j++) {
                if(numbers[j] > numbers[j + 1]) {
                    swap = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = swap;
                }
            }
        }
    }
}
