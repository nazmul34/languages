function isEven(n) {
  return n % 2 === 0;
}

function main() {
  const numbers = [5, 1, 4, 2, 3];
  const evenSquares = [];

  for (const n of numbers) {
    if (isEven(n)) {
      evenSquares.push(n * n);
    }
  }

  const total = evenSquares.reduce((acc, value) => acc + value, 0);

  console.log("Language: JavaScript");
  console.log(`Input: ${JSON.stringify(numbers)}`);
  console.log(`Even squares: ${JSON.stringify(evenSquares)}`);
  console.log(`Total: ${total}`);
}

main();
