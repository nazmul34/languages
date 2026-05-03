const fs = require("fs");
const fsp = require("fs/promises");
const path = require("path");

async function main() {
  console.log("Language: JavaScript");

  const baseDir = __dirname;
  const dataDir = path.join(baseDir, "data");
  await fsp.mkdir(dataDir, { recursive: true });

  const textPath = path.join(dataDir, "sample.txt");
  const jsonPath = path.join(dataDir, "sample.json");
  const csvPath = path.join(dataDir, "sample.csv");

  // Write text using a buffered stream.
  await new Promise((resolve, reject) => {
    const stream = fs.createWriteStream(textPath, { encoding: "utf8", highWaterMark: 16 * 1024 });
    stream.on("error", reject);
    stream.on("finish", resolve);
    stream.write("line-1\n");
    stream.write("line-2\n");
    stream.end();
  });

  // Read text back.
  const textContent = await fsp.readFile(textPath, "utf8");
  console.log("Text read:\n" + textContent.trim());

  // JSON write/read.
  const payload = {
    name: "Nazmul",
    skills: ["python", "javascript", "java", "csharp", "cpp"],
    active: true,
  };
  await fsp.writeFile(jsonPath, JSON.stringify(payload, null, 2), "utf8");
  const parsedJson = JSON.parse(await fsp.readFile(jsonPath, "utf8"));
  console.log("JSON parsed:", parsedJson);

  // CSV write/read (manual parsing for comparison purpose).
  const csvRows = [
    "id,name,score",
    "1,Alice,95",
    "2,Bob,88",
  ];
  await fsp.writeFile(csvPath, csvRows.join("\n") + "\n", "utf8");

  const csvContent = await fsp.readFile(csvPath, "utf8");
  const [headerLine, ...dataLines] = csvContent.trim().split("\n");
  const headers = headerLine.split(",");
  const parsedCsv = dataLines.map((line) => {
    const parts = line.split(",");
    return Object.fromEntries(headers.map((h, i) => [h, parts[i]]));
  });
  console.log("CSV parsed:", parsedCsv);

  // Path API examples.
  console.log("Path exists:", fs.existsSync(textPath));
  console.log("Path basename:", path.basename(textPath));
  console.log("Path dirname:", path.dirname(textPath));
}

main().catch((err) => {
  console.error("Error:", err);
  process.exit(1);
});
