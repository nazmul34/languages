import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SyntaxSimplicity {
    private static boolean isEven(int n) {
        return n % 2 == 0;
    }

    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(5, 1, 4, 2, 3);
        List<Integer> evenSquares = new ArrayList<>();

        for (int n : numbers) {
            if (isEven(n)) {
                evenSquares.add(n * n);
            }
        }

        int total = 0;
        for (int value : evenSquares) {
            total += value;
        }

        System.out.println("Language: Java");
        System.out.println("Input: " + numbers);
        System.out.println("Even squares: " + evenSquares);
        System.out.println("Total: " + total);
    }
}
