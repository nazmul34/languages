function main() {
  console.log("Language: JavaScript");

  const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  // --- Lambdas (arrow functions) ---
  const double = (x) => x * 2;
  const isEven = (x) => x % 2 === 0;
  const add = (a, b) => a + b;
  console.log("Arrow fn double(5):  ", double(5));

  // --- map ---
  const doubled = numbers.map(double);
  console.log("map (double):        ", doubled);

  // --- filter ---
  const evens = numbers.filter(isEven);
  console.log("filter (evens):      ", evens);

  // --- reduce ---
  const total = numbers.reduce(add, 0);
  console.log("reduce (sum):        ", total);

  // --- Composed pipeline (method chaining) ---
  const result = numbers
    .filter(isEven)
    .map(double)
    .reduce(add, 0);
  console.log("filter→map→reduce:  ", result); // even numbers, doubled, summed

  // --- Immutability patterns ---
  // const prevents rebinding; spread creates shallow copies
  const original = Object.freeze([1, 2, 3]);
  const extended = [...original, 4, 5]; // new array — original unchanged
  console.log("Frozen original:     ", original);
  console.log("Extended (new):      ", extended);

  // Object.freeze for shallow immutable objects
  const config = Object.freeze({ host: "localhost", port: 8080 });
  const updated = { ...config, port: 9090 }; // new object
  console.log("Frozen config:       ", config);
  console.log("Updated (new):       ", updated);

  console.log("Original numbers unchanged:", numbers);
}

main();
