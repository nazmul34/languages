import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

public class SortingSearching {

    // --- Manual algorithms ---

    static int[] bubbleSort(int[] input) {
        int[] arr = input.clone();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        return arr;
    }

    static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) return arr.clone();
        int mid = arr.length / 2;
        int[] left = mergeSort(Arrays.copyOfRange(arr, 0, mid));
        int[] right = mergeSort(Arrays.copyOfRange(arr, mid, arr.length));
        return merge(left, right);
    }

    static int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        while (i < left.length && j < right.length) {
            result[k++] = left[i] <= right[j] ? left[i++] : right[j++];
        }
        while (i < left.length) result[k++] = left[i++];
        while (j < right.length) result[k++] = right[j++];
        return result;
    }

    static int binarySearch(int[] arr, int target) {
        int lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("Language: Java");
        int[] unsorted = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original:           " + Arrays.toString(unsorted));

        // Manual sorts
        System.out.println("Bubble sort:        " + Arrays.toString(bubbleSort(unsorted)));
        System.out.println("Merge sort:         " + Arrays.toString(mergeSort(unsorted)));

        // Built-in sort (dual-pivot quicksort for primitives)
        int[] builtIn = unsorted.clone();
        Arrays.sort(builtIn);
        System.out.println("Arrays.sort():      " + Arrays.toString(builtIn));

        // Manual binary search
        int[] sorted = mergeSort(unsorted);
        System.out.println("Manual binary search for 25: index " + binarySearch(sorted, 25));

        // Built-in binary search
        System.out.println("Arrays.binarySearch() for 25: index " + Arrays.binarySearch(sorted, 25));

        // Collections.sort on a List
        List<Integer> list = new ArrayList<>(List.of(64, 34, 25, 12, 22, 11, 90));
        Collections.sort(list);
        System.out.println("Collections.sort(): " + list);
    }
}
