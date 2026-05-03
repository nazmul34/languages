import asyncio
import threading
import time
from concurrent.futures import ThreadPoolExecutor


# --- Threads ---

def worker(name: str, delay: float) -> str:
    time.sleep(delay)
    return f"Thread '{name}' done after {delay}s"


def run_threads() -> None:
    print("\n-- Threads --")
    with ThreadPoolExecutor(max_workers=3) as executor:
        futures = [
            executor.submit(worker, "A", 0.2),
            executor.submit(worker, "B", 0.1),
            executor.submit(worker, "C", 0.05),
        ]
        for f in futures:
            print(f.result())


# --- async/await (event loop model) ---

async def fetch_data(name: str, delay: float) -> str:
    await asyncio.sleep(delay)   # non-blocking wait
    return f"Data from '{name}'"


async def run_async() -> None:
    print("\n-- async/await (event loop) --")

    # Sequential
    result_a = await fetch_data("source-A", 0.1)
    result_b = await fetch_data("source-B", 0.1)
    print("Sequential:", result_a, "|", result_b)

    # Parallel with asyncio.gather
    results = await asyncio.gather(
        fetch_data("source-X", 0.2),
        fetch_data("source-Y", 0.1),
        fetch_data("source-Z", 0.05),
    )
    print("Parallel gather:", results)


def main() -> None:
    print("Language: Python")

    # Threads (OS threads, but GIL limits CPU parallelism for pure Python)
    run_threads()

    # Event loop — single-threaded cooperative concurrency
    asyncio.run(run_async())


if __name__ == "__main__":
    main()
