import csv
import json
from pathlib import Path


def main() -> None:
    print("Language: Python")

    base_dir = Path(__file__).resolve().parent
    data_dir = base_dir / "data"
    data_dir.mkdir(exist_ok=True)

    text_path = data_dir / "sample.txt"
    json_path = data_dir / "sample.json"
    csv_path = data_dir / "sample.csv"

    # Write text with buffering and newline handling.
    with text_path.open("w", encoding="utf-8", buffering=8192) as f:
        f.write("line-1\n")
        f.write("line-2\n")

    # Read text back.
    with text_path.open("r", encoding="utf-8") as f:
        text_content = f.read()
    print("Text read:")
    print(text_content.strip())

    # JSON write/read.
    payload = {
        "name": "Nazmul",
        "skills": ["python", "javascript", "java", "csharp", "cpp"],
        "active": True
    }
    with json_path.open("w", encoding="utf-8") as f:
        json.dump(payload, f, indent=2)
    with json_path.open("r", encoding="utf-8") as f:
        parsed_json = json.load(f)
    print("JSON parsed:", parsed_json)

    # CSV write/read.
    rows = [
        ["id", "name", "score"],
        ["1", "Alice", "95"],
        ["2", "Bob", "88"]
    ]
    with csv_path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(rows)

    with csv_path.open("r", encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f)
        parsed_csv = list(reader)
    print("CSV parsed:", parsed_csv)

    # Path API examples.
    print("Path exists:", text_path.exists())
    print("Path name:", text_path.name)
    print("Parent dir:", text_path.parent)


if __name__ == "__main__":
    main()
