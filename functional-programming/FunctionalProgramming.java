import java.util.Arrays;
import java.util.List;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class FunctionalProgramming {
    public static void main(String[] args) {
        System.out.println("Language: Java");

        List<Integer> numbers = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        // --- Lambdas ---
        Function<Integer, Integer> doubleIt = x -> x * 2;
        Predicate<Integer> isEven = x -> x % 2 == 0;
        BiFunction<Integer, Integer, Integer> add = (a, b) -> a + b;
        System.out.println("Lambda double(5):   " + doubleIt.apply(5));

        // --- map (Stream.map) ---
        List<Integer> doubled = numbers.stream()
                .map(doubleIt)
                .collect(Collectors.toList());
        System.out.println("map (double):       " + doubled);

        // --- filter (Stream.filter) ---
        List<Integer> evens = numbers.stream()
                .filter(isEven)
                .collect(Collectors.toList());
        System.out.println("filter (evens):     " + evens);

        // --- reduce (Stream.reduce) ---
        int total = numbers.stream()
                .reduce(0, Integer::sum);
        System.out.println("reduce (sum):       " + total);

        // --- Composed pipeline ---
        int result = numbers.stream()
                .filter(isEven)
                .map(doubleIt)
                .reduce(0, Integer::sum);
        System.out.println("filter→map→reduce: " + result);

        // --- Immutability patterns ---
        // List.of() is unmodifiable
        List<Integer> original = List.of(1, 2, 3);
        // original.add(4) would throw UnsupportedOperationException
        List<Integer> extended = new java.util.ArrayList<>(original);
        extended.add(4);
        System.out.println("Unmodifiable original: " + original);
        System.out.println("New extended list:     " + extended);

        System.out.println("Original numbers unchanged: " + numbers);
    }
}
