## Láncolt lista

Implementáljunk egy `double` adattagokat tároló, egyszeresen láncolt lista adatszerkezetet 
([singly-linked list](https://en.wikipedia.org/wiki/Linked_list)). Bontsuk egy `.cpp` és
egy header fájlra, a főprogram pedig különüljön el mindkettőtől. A megvalósitandó műveletek
listája és egyben a header fájl váza legyen a következő:

```c++
class Node {
  friend class List;

  double data;
  Node *next;

public:
  Node(double input);
};

class List {
  Node *head;

public:
  List();
  ~List();

  // Remove element by value.
  void remove(double element);
  
  // Remove element at given index.
  void remove(int index);

  // Append to the end of the list.
  void append(double element);

  // Insert element to given index.
  void insert(int index, double element);

  // Return number of elements.
  int size() const;

  // Print elements.
  void print() const;
};
```

Gondoljátok végig a a szélsőséges eseteket (pl. üres listába beszúrás; ha olyan elemet kell törölni,
ami nincs benne a listában, stb)! Ti választjátok meg, hogyan viselkedjen a listátok
ezekben az esetekben, a lényeg, hogy a felhasználó számára intuitiv és könnyen használható
legyen.

Figyeljetek emellett a memóriahasználatra! Törléskor és a destruktorban szabaditsátok fel a
lefoglalt területeket. Ellenőrzésképp használhatjátok a [Valgrind](http://valgrind.org/) (Linux),
[Dr. Memory](https://drmemory.org/) (Windows) vagy hasonló eszközöket.

Példa `main()` és kimenet:

```c++
#include <iostream>
#include "list.h"

int main() {
  List l = List();
  l.append(3.1);
  l.append(-2.5);
  l.append(8.);
  l.print();
  std::cout << "size: " << l.size() << '\n';
  
  l.remove(0);
  l.print();
  l.remove(5);
  l.print();
  l.remove(1);
  l.print();
  l.remove(0);
  l.print();
  
  l.insert(0, 3.14);
  l.insert(8, 123.);
  l.insert(1, 42.);
  l.print();
}
```

```
$ ./list
3.1 -2.5 8 
size: 3
-2.5 8 
-2.5 8 
-2.5 
(empty)
3.14 42 123
```

### Extra feladatok

Tegyük fel, hogy a listánk `int`-eket tárol.

1. Irjunk egy metódust, ami eltünteti a duplikátumokat a listából.

2. Irjunk egy metódust, ami visszaadja a hátulról számitott *k*-adik elemet.

3. Irjunk egy metódust, ami leellenőrzi, hogy a lista palindróma-e.
