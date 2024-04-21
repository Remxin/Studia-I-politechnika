def left(s: str, n: int):
    if len(s) > n:
        raise("Linia tekstu za długa")
    
    print(s + "".join([" " for _ in range(0, n-len(s))]))


def right(s: str, n:int):
    if len(s) > n:
        raise("Linia tekstu za długa")
    
    print("".join([" " for _ in range(0, n-len(s))]) + s)


def center(s: str, n: int):
    if len(s) > n:
        raise("Linia tekstu za długa")
    
    pol = n // 2
    print("".join([" " for _ in range(0, pol)]) + s + "".join([" " for _ in range(0, n-pol)]))


if __name__ == '__main__':
    #kod został uruchomiony jako program
    pass
else:
    n = 80
    #plik został zaimportowany jako moduł
    print("Moduł 'text' definiuje funkcje center, left, right i służy do:\n")
    left("wyrownania tekstu do lewej", n)
    right("do prawej", n)
    center("do srodka")
    print("i inne funkcje", dir())

  