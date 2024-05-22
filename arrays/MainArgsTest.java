public class MainArgsTest {
	public static void main(String[] words) {
		if (words.length == 0) {
			System.out.println("No args");
		} else {
			for(String word : words) {
				System.out.println(word);
			}
		}
	}
}
