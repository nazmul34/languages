import gc
import time


class BigObject:
    def __init__(self, size: int):
        self.data = [0] * size


def lifetime_demo() -> None:
    print("\n-- Object lifetime --")
    obj = BigObject(100_000)
    print("Object created, len(data)=", len(obj.data))
    del obj
    print("Reference deleted; Python uses ref counting + cyclic GC")


def gc_demo() -> None:
    print("\n-- Garbage collection --")
    print("GC counts before:", gc.get_count())
    tmp = [BigObject(10_000) for _ in range(100)]
    del tmp
    collected = gc.collect()
    print("Forced gc.collect() reclaimed objects:", collected)
    print("GC counts after:", gc.get_count())


def performance_tradeoff() -> None:
    print("\n-- Performance tradeoff --")
    start = time.perf_counter()
    nums = []
    for i in range(500_000):
        nums.append(i)
    elapsed = time.perf_counter() - start
    print(f"Allocated 500000 integers in {elapsed:.4f}s")
    print("Tradeoff: automatic memory management is safer but has GC/runtime overhead")


def main() -> None:
    print("Language: Python")
    lifetime_demo()
    gc_demo()
    performance_tradeoff()


if __name__ == "__main__":
    main()
