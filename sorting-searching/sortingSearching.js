// --- Manual algorithms ---

function bubbleSort(arr) {
  const result = [...arr];
  const n = result.length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      if (result[j] > result[j + 1]) {
        [result[j], result[j + 1]] = [result[j + 1], result[j]];
      }
    }
  }
  return result;
}

function mergeSort(arr) {
  if (arr.length <= 1) return [...arr];
  const mid = Math.floor(arr.length / 2);
  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));
  return merge(left, right);
}

function merge(left, right) {
  const result = [];
  let i = 0;
  let j = 0;
  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      result.push(left[i++]);
    } else {
      result.push(right[j++]);
    }
  }
  return result.concat(left.slice(i)).concat(right.slice(j));
}

function binarySearch(arr, target) {
  let lo = 0;
  let hi = arr.length - 1;
  while (lo <= hi) {
    const mid = Math.floor((lo + hi) / 2);
    if (arr[mid] === target) return mid;
    else if (arr[mid] < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return -1;
}

function main() {
  console.log("Language: JavaScript");
  const unsorted = [64, 34, 25, 12, 22, 11, 90];
  console.log("Original:          ", unsorted);

  // Manual sorts
  console.log("Bubble sort:       ", bubbleSort(unsorted));
  console.log("Merge sort:        ", mergeSort(unsorted));

  // Built-in sort (note: must pass comparator for numeric sort)
  const builtIn = [...unsorted].sort((a, b) => a - b);
  console.log("Built-in sort():   ", builtIn);

  // Manual binary search
  const sorted = [...unsorted].sort((a, b) => a - b);
  const idx = binarySearch(sorted, 25);
  console.log(`Manual binary search for 25: index ${idx}`);

  // Built-in search
  console.log(`Array.indexOf() for 25:      index ${sorted.indexOf(25)}`);
  console.log(`Array.findIndex() for 25:    index ${sorted.findIndex((x) => x === 25)}`);
}

main();
