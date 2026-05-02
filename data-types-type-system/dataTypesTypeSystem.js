function describeTypes() {
  const age = 28;
  const temperature = 36.7;
  const name = "Nazmul";
  const isActive = true;
  const tags = ["javascript", "types", "demo"];
  const scores = { math: 90, science: 88 };
  const middleName = null;

  const convertedAge = String(age);
  const parsedNumber = Number("42");

  console.log("Language: JavaScript");
  console.log(`age=${age} (${typeof age})`);
  console.log(`temperature=${temperature} (${typeof temperature})`);
  console.log(`name=${name} (${typeof name})`);
  console.log(`isActive=${isActive} (${typeof isActive})`);
  console.log(`tags=${JSON.stringify(tags)} (${Array.isArray(tags) ? "array" : typeof tags})`);
  console.log(`scores=${JSON.stringify(scores)} (${typeof scores})`);
  console.log(`middleName=${middleName} (${typeof middleName})`);
  console.log(`convertedAge=${convertedAge} (${typeof convertedAge})`);
  console.log(`parsedNumber=${parsedNumber} (${typeof parsedNumber})`);
}

describeTypes();
