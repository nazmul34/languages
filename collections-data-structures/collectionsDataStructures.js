function main() {
  console.log("Language: JavaScript");

  // Array
  const numbersArray = [10, 20, 30];
  console.log("Array:", numbersArray);

  // List-like operations (JavaScript arrays are dynamic)
  const numbersList = [1, 2, 3];
  numbersList.push(4);
  console.log("List-like array:", numbersList);

  // Map (dictionary)
  const scores = new Map([
    ["alice", 95],
    ["bob", 88],
  ]);
  scores.set("carol", 91);
  console.log("Map:", Object.fromEntries(scores));

  // Set
  const uniqueValues = new Set([1, 2, 2, 3]);
  uniqueValues.add(4);
  console.log("Set:", Array.from(uniqueValues));

  // Queue (FIFO) using array
  const queue = ["first", "second"];
  queue.push("third");
  const removedFromQueue = queue.shift();
  console.log("Queue removed:", removedFromQueue, "Remaining:", queue);

  // Stack (LIFO) using array
  const stack = ["bottom", "middle"];
  stack.push("top");
  const removedFromStack = stack.pop();
  console.log("Stack removed:", removedFromStack, "Remaining:", stack);
}

main();
