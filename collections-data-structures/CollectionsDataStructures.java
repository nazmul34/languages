import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class CollectionsDataStructures {
    public static void main(String[] args) {
        System.out.println("Language: Java");

        // Array
        int[] numbersArray = {10, 20, 30};
        System.out.println("Array: " + java.util.Arrays.toString(numbersArray));

        // List
        List<Integer> numbersList = new ArrayList<>(List.of(1, 2, 3));
        numbersList.add(4);
        System.out.println("List: " + numbersList);

        // Map
        Map<String, Integer> scores = new HashMap<>();
        scores.put("alice", 95);
        scores.put("bob", 88);
        scores.put("carol", 91);
        System.out.println("Map: " + scores);

        // Set
        Set<Integer> uniqueValues = new HashSet<>(List.of(1, 2, 2, 3));
        uniqueValues.add(4);
        System.out.println("Set: " + uniqueValues);

        // Queue (FIFO)
        Queue<String> queue = new ArrayDeque<>();
        queue.offer("first");
        queue.offer("second");
        queue.offer("third");
        String removedFromQueue = queue.poll();
        System.out.println("Queue removed: " + removedFromQueue + " Remaining: " + queue);

        // Stack (LIFO) using Deque
        ArrayDeque<String> stack = new ArrayDeque<>();
        stack.push("bottom");
        stack.push("middle");
        stack.push("top");
        String removedFromStack = stack.pop();
        System.out.println("Stack removed: " + removedFromStack + " Remaining: " + stack);
    }
}
