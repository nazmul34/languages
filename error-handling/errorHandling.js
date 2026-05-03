class AgeError extends Error {
  constructor(message) {
    super(message);
    this.name = "AgeError";
  }
}

class ConfigError extends Error {
  constructor(message) {
    super(message);
    this.name = "ConfigError";
  }
}

function parseAge(text) {
  const age = Number(text);
  if (Number.isNaN(age)) {
    throw new AgeError(`Age must be a number: ${text}`);
  }
  if (age < 0) {
    throw new AgeError("Age cannot be negative");
  }
  return age;
}

function loadConfig(data) {
  if (!Object.prototype.hasOwnProperty.call(data, "mode")) {
    throw new ConfigError("Missing 'mode' in config");
  }
  return data.mode;
}

function checkedVsUncheckedNote() {
  console.log("JavaScript note: no checked exceptions; all throws are runtime.");
}

function main() {
  console.log("Language: JavaScript");

  try {
    console.log("Parsed age:", parseAge("21"));
    console.log("Parsed age:", parseAge("oops"));
  } catch (err) {
    if (err instanceof AgeError) {
      console.log("Caught custom exception:", err.message);
    } else {
      console.log("Caught unexpected error:", err);
    }
  } finally {
    console.log("Finally block: cleanup/logging runs always");
  }

  try {
    const mode = loadConfig({});
    console.log("Mode:", mode);
  } catch (err) {
    if (err instanceof ConfigError) {
      console.log("Caught runtime-style custom exception:", err.message);
    }
  }

  checkedVsUncheckedNote();
}

main();
