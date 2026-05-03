import java.util.List;
import java.util.concurrent.*;

public class ConcurrencyAsync {

    // --- Runnable: fire-and-forget thread ---
    static void runThreads() throws InterruptedException {
        System.out.println("\n-- Threads --");
        Thread t1 = new Thread(() -> System.out.println("Thread A running"));
        Thread t2 = new Thread(() -> System.out.println("Thread B running"));
        t1.start();
        t2.start();
        t1.join();
        t2.join();
    }

    // --- Callable + Future: return a value from a thread ---
    static String fetchData(String name, long delayMs) throws InterruptedException {
        Thread.sleep(delayMs);
        return "Data from '" + name + "'";
    }

    static void runExecutorService() throws Exception {
        System.out.println("\n-- ExecutorService + Future --");
        ExecutorService pool = Executors.newFixedThreadPool(3);

        Future<String> fa = pool.submit(() -> fetchData("source-A", 200));
        Future<String> fb = pool.submit(() -> fetchData("source-B", 100));
        Future<String> fc = pool.submit(() -> fetchData("source-C", 50));

        // Blocks until result is available
        System.out.println(fa.get());
        System.out.println(fb.get());
        System.out.println(fc.get());
        pool.shutdown();
    }

    // --- CompletableFuture: async/await equivalent ---
    static void runCompletableFuture() throws Exception {
        System.out.println("\n-- CompletableFuture (async/await style) --");

        CompletableFuture<String> cf = CompletableFuture
                .supplyAsync(() -> "raw-data")
                .thenApply(s -> s.toUpperCase())         // like .then() / map
                .thenApply(s -> "Processed: " + s);

        System.out.println(cf.get());                    // blocks for result

        // Parallel execution with allOf
        CompletableFuture<String> x = CompletableFuture.supplyAsync(() -> "X");
        CompletableFuture<String> y = CompletableFuture.supplyAsync(() -> "Y");
        CompletableFuture<Void> all = CompletableFuture.allOf(x, y);
        all.get();
        System.out.println("allOf results: " + x.get() + ", " + y.get());
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Language: Java");
        runThreads();
        runExecutorService();
        runCompletableFuture();
    }
}
