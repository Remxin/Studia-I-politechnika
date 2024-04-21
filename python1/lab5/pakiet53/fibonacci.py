def fibonacci_iterative(n):
    """Funkcja obliczająca n-ty wyraz ciągu Fibonacciego iteracyjnie."""
    if n <= 1:
        return n
    else:
        fib_prev = 0
        fib_current = 1
        for _ in range(2, n + 1):
            fib_prev, fib_current = fib_current, fib_prev + fib_current
        return fib_current

def fibonacci_recursive(n):
    """Funkcja obliczająca n-ty wyraz ciągu Fibonacciego rekurencyjnie."""
    if n <= 1:
        return n
    else:
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)