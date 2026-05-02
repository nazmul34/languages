function greet(name, prefix = "Hello") {
  return `${prefix}, ${name}!`;
}

function add(a, b = 0) {
  return a + b;
}

function applyOperation(a, b, operation) {
  return operation(a, b);
}

function main() {
  // Default parameter
  console.log(greet("Nazmul"));

  // Named parameter style via object destructuring
  function greetNamed({ name, prefix = "Hello" }) {
    return `${prefix}, ${name}!`;
  }
  console.log(greetNamed({ name: "Nazmul", prefix: "Hi" }));

  // JavaScript has no compile-time overloading; defaults or checks are common
  console.log(add(10));
  console.log(add(10, 5));

  // First-class function
  const multiply = (x, y) => x * y;
  console.log(applyOperation(4, 3, multiply));
}

main();
