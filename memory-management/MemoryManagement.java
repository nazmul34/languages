import java.util.ArrayList;
import java.util.List;

class BigObject {
    int[] data;

    BigObject(int size) {
        this.data = new int[size];
    }
}

public class MemoryManagement {

    static void lifetimeDemo() {
        System.out.println("\n-- Object lifetime --");
        BigObject obj = new BigObject(100_000);
        System.out.println("Object created, len(data)= " + obj.data.length);
        obj = null;
        System.out.println("Reference cleared; object is eligible for GC");
    }

    static void gcDemo() {
        System.out.println("\n-- Garbage collection --");
        Runtime rt = Runtime.getRuntime();
        long before = rt.totalMemory() - rt.freeMemory();
        System.out.println("Used memory before: " + before / (1024 * 1024) + " MB");

        List<BigObject> tmp = new ArrayList<>();
        for (int i = 0; i < 200; i++) {
            tmp.add(new BigObject(20_000));
        }
        tmp = null;

        System.gc();
        long after = rt.totalMemory() - rt.freeMemory();
        System.out.println("Used memory after:  " + after / (1024 * 1024) + " MB");
        System.out.println("Note: System.gc() is only a request to the JVM");
    }

    static void performanceTradeoff() {
        System.out.println("\n-- Performance tradeoff --");
        long start = System.nanoTime();
        List<Object> list = new ArrayList<>();
        for (int i = 0; i < 500_000; i++) {
            list.add(new Object());
        }
        long elapsedMs = (System.nanoTime() - start) / 1_000_000;
        System.out.println("Allocated 500000 objects in " + elapsedMs + " ms");
        System.out.println("Tradeoff: GC reduces leaks/dangling pointers but adds runtime overhead");
    }

    public static void main(String[] args) {
        System.out.println("Language: Java");
        lifetimeDemo();
        gcDemo();
        performanceTradeoff();
    }
}
