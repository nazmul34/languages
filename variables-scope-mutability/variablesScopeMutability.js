function mutateArray(items) {
  items.push("new-item");
}

function main() {
  let mutableCount = 1;
  const immutableName = "Nazmul";

  const items = ["a", "b"];
  const config = { mode: "demo" };

  // Block scope example
  let scopeValue = "outside";
  if (true) {
    const insideBlock = "inside";
    scopeValue = insideBlock;
  }

  // Mutability examples
  mutateArray(items);
  config.mode = "updated";

  // Reassignment example
  mutableCount = mutableCount + 1;

  console.log("Language: JavaScript");
  console.log(`immutableName=${immutableName}`);
  console.log(`mutableCount=${mutableCount}`);
  console.log(`scopeValue=${scopeValue}`);
  console.log(`items=${JSON.stringify(items)}`);
  console.log(`config=${JSON.stringify(config)}`);
}

main();
