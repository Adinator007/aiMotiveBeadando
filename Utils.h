#pragma once
#include <fstream>
#include "Terkep.h"
#include "Field.h"
#include "StartMezo.h"
#include "UresMezo.h"
#include "Akadaly.h"
#include "Cel.h"

/**
* Fuggveny, amely karaktert hexadecimalis szamjegykent ertelmezve integerre valtoztat.
* Pl.: 'C' -> 12
*      '9' -> 9
* (kisbetuket nem ertelmez helyesen)
**/
int charToHex(char c);

int bfs(int x, int y, Terkep* terkep);


/**
* Factory methodus, amely letrehozza a megfelelo tipusu Field objektumot es visszater azzal.
**/
Field* FieldFactory(char c);

/**
* Segedfuggveny, amely megadja, hogy a parameterkent megkapott karakter hexadecimalis karakternek szamit-e.
* (Benne van-e az alabbi betukben: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F})
**/
bool isHexa(char c);

/**
* Beolvasast vegzo fuggveny.
* startX: referenciaval atadott argumentum. Ebbe lesz beleirva a start mezonek az x koordinataja.
* startY: referenciaval atadott argumentum. Ebbe lesz beleirva a start mezonek az y koordinataja.
* Return value: pointer a frissen beolvasott es allokalt Terkep objektumra.
**/
Terkep* beolvas(int& startX, int& startY);