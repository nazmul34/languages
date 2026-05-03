// JavaScript runs on a single-threaded event loop.
// True parallelism requires Worker Threads (Node.js) or Web Workers (browser).

const { Worker, isMainThread, parentPort, workerData } = require("worker_threads");

// --- async/await & Promises (event loop model) ---

async function fetchData(name, delayMs) {
  await new Promise((resolve) => setTimeout(resolve, delayMs));
  return `Data from '${name}'`;
}

async function runAsync() {
  console.log("\n-- async/await (event loop) --");

  // Sequential: each await waits before the next starts
  const a = await fetchData("source-A", 100);
  const b = await fetchData("source-B", 100);
  console.log("Sequential:", a, "|", b);

  // Parallel: Promise.all runs concurrently on the event loop
  const results = await Promise.all([
    fetchData("source-X", 200),
    fetchData("source-Y", 100),
    fetchData("source-Z", 50),
  ]);
  console.log("Promise.all parallel:", results);

  // Promise.allSettled — collects results even if some reject
  const settled = await Promise.allSettled([
    fetchData("ok", 50),
    Promise.reject(new Error("simulated failure")),
  ]);
  settled.forEach((r) =>
    console.log("allSettled:", r.status, r.value ?? r.reason?.message)
  );
}

// --- Worker Threads (true parallelism in Node.js) ---

function runWorkerThread() {
  return new Promise((resolve, reject) => {
    const worker = new Worker(
      `
      const { parentPort, workerData } = require('worker_threads');
      // CPU-bound work isolated from the main thread
      let sum = 0;
      for (let i = 0; i < workerData.count; i++) sum += i;
      parentPort.postMessage({ thread: workerData.name, sum });
      `,
      { eval: true, workerData: { name: "worker-1", count: 1_000_000 } }
    );
    worker.on("message", resolve);
    worker.on("error", reject);
  });
}

async function main() {
  console.log("Language: JavaScript");

  await runAsync();

  console.log("\n-- Worker Thread (parallel CPU work) --");
  const result = await runWorkerThread();
  console.log(`Worker result: thread=${result.thread}, sum=${result.sum}`);
}

main();
