## +/- javító beadandó

Irjátok meg az `ArrayOnHeap` osztályt, ami két dolgot tárol: mutatót egy integer tömbre a heapen, és a tömb elemszámát. Létrehozáskor két adatot kap, egy default értéket, amivel feltölti a tömböt, és az elemszámot.

A cél, hogy a `main.cpp` hiba nélkül leforduljon és lefusson, változtatás nélkül, az alábbi forditási paranccsal:

```
$ g++ -fsanitize=address main.cpp
```
Az igy bekapcsolt [Address Sanitizer](https://en.wikipedia.org/wiki/AddressSanitizer) elgáncsolja a programot futási időben, ha memory leak van benne.

**Határidő:** május 19. vasárnap éjfél.
