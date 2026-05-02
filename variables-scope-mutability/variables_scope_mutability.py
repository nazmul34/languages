def mutate_list(items):
    items.append("new-item")


def main():
    mutable_count = 1
    immutable_name = "Nazmul"

    items = ["a", "b"]
    config = {"mode": "demo"}

    # Function scope example
    def inner_scope():
        local_value = "inside"
        return local_value

    scope_value = inner_scope()

    # Mutability examples
    mutate_list(items)
    config["mode"] = "updated"

    # Rebinding example
    mutable_count = mutable_count + 1

    print("Language: Python")
    print(f"immutable_name={immutable_name}")
    print(f"mutable_count={mutable_count}")
    print(f"scope_value={scope_value}")
    print(f"items={items}")
    print(f"config={config}")


if __name__ == "__main__":
    main()
