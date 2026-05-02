import java.util.function.BiFunction;

public class FunctionsParameters {
    // Java has no default parameters; overloads are a common pattern.
    static String greet(String name) {
        return greet(name, "Hello");
    }

    static String greet(String name, String prefix) {
        return prefix + ", " + name + "!";
    }

    // Overloading example
    static int add(int a) {
        return add(a, 0);
    }

    static int add(int a, int b) {
        return a + b;
    }

    static int applyOperation(int a, int b, BiFunction<Integer, Integer, Integer> operation) {
        return operation.apply(a, b);
    }

    public static void main(String[] args) {
        System.out.println(greet("Nazmul"));

        // Java has no named parameters. Use explicit argument order.
        System.out.println(greet("Nazmul", "Hi"));

        System.out.println(add(10));
        System.out.println(add(10, 5));

        // First-class function: a lambda can be stored in a variable and passed to another function.
        BiFunction<Integer, Integer, Integer> multiply = (x, y) -> x * y;
        System.out.println(applyOperation(4, 3, multiply));
    }
}
