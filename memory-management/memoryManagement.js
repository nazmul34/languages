function formatMB(bytes) {
  return (bytes / (1024 * 1024)).toFixed(2) + " MB";
}

class BigObject {
  constructor(size) {
    this.data = new Array(size).fill(0);
  }
}

function lifetimeDemo() {
  console.log("\n-- Object lifetime --");
  let obj = new BigObject(100_000);
  console.log("Object created, len(data)=", obj.data.length);
  obj = null;
  console.log("Reference cleared; object is eligible for GC");
}

function gcDemo() {
  console.log("\n-- Garbage collection --");
  const before = process.memoryUsage();
  console.log("Heap used before:", formatMB(before.heapUsed));

  let tmp = [];
  for (let i = 0; i < 200; i++) tmp.push(new BigObject(20_000));
  tmp = null;

  if (global.gc) {
    global.gc();
    console.log("Forced GC using global.gc() (run node with --expose-gc)");
  } else {
    console.log("GC is automatic; enable --expose-gc for manual trigger demo");
  }

  const after = process.memoryUsage();
  console.log("Heap used after:", formatMB(after.heapUsed));
}

function performanceTradeoff() {
  console.log("\n-- Performance tradeoff --");
  const t0 = performance.now();
  const arr = [];
  for (let i = 0; i < 500_000; i++) arr.push({ value: i });
  const t1 = performance.now();
  console.log(`Allocated 500000 objects in ${(t1 - t0).toFixed(2)} ms`);
  console.log("Tradeoff: GC improves safety but can introduce pause/throughput overhead");
}

function main() {
  console.log("Language: JavaScript");
  lifetimeDemo();
  gcDemo();
  performanceTradeoff();
}

main();
