#include <iostream>
#include "Utils.h"

/**
* Fuggveny, amely karaktert hexadecimalis szamjegykent ertelmezve integerre valtoztat.
* Pl.: 'C' -> 12
*      '9' -> 9
* (kisbetuket nem ertelmez helyesen)
**/
int charToHex(char c) {
    if (c >= 48 && c <= 57) { // szamjegyrol van szo
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }
    return 0;
}


/**
* Szelessegi keresest megvalosito algoritmus.
* Return value: Az osszes celmezohoz valo tavolsagok osszege a start mezotol.
**/
int bfs(int x, int y, Terkep* terkep) {
    std::queue<std::pair<int, int>> sor;
    sor.push(std::make_pair(x, y));
    terkep->setTavolsag(x, y, 0);
    while (!sor.empty()) {
        std::pair<int, int> node = sor.front();
        sor.pop();
        x = node.first;
        y = node.second;
        std::pair<int, int> kovetkezoNodeFel = terkep->Leptet(x, y, Fel, terkep->getTavolsag(x, y));
        if (kovetkezoNodeFel.first != -1) { // hibakod arra az esetre, ha nem lehetne 'Fel' iranyba lepni az aktualis mezorol
            // A sorba valo beszurast rendellenes modon a terkep vegzi. Ennek az az oka, hogy elkeruljuk a type-check-et.
            // vagyis, hogy ne kelljen lekerdezni az egyes Field-ek tipusat. A cel mezoket nem szurjuk vissza a sorba,
            // hiszen onnan nem folytatodhatnak utak. Jelen megoldasban oroklest hasznalva oldottam meg a beszuras problemajat.
            // Ennek elonye, hogy a sorbaszuras logikaja lokalizalt az egyes Field altipusokra, viszont hatranya, hogy a terkepnek olyasmivel
            // kell foglalkoznia, ami nem feltetlen hozza tartozik (BFS algoritmus).
            terkep->Berak(kovetkezoNodeFel.first, kovetkezoNodeFel.second, sor);
        }
        std::pair<int, int> kovetkezoNodeLe = terkep->Leptet(x, y, Le, terkep->getTavolsag(x, y));
        if (kovetkezoNodeLe.first != -1) {
            terkep->Berak(kovetkezoNodeLe.first, kovetkezoNodeLe.second, sor);
        }
        std::pair<int, int> kovetkezoNodeJobb = terkep->Leptet(x, y, Jobb, terkep->getTavolsag(x, y));
        if (kovetkezoNodeJobb.first != -1) {
            terkep->Berak(kovetkezoNodeJobb.first, kovetkezoNodeJobb.second, sor);
        }
        std::pair<int, int> kovetkezoNodeBal = terkep->Leptet(x, y, Bal, terkep->getTavolsag(x, y));
        if (kovetkezoNodeBal.first != -1) {
            terkep->Berak(kovetkezoNodeBal.first, kovetkezoNodeBal.second, sor);
        }
    }
    return terkep->celMezokTavolsagOsszege();
}


/**
* Factory methodus, amely letrehozza a megfelelo tipusu Field objektumot es visszater azzal.
**/
Field* FieldFactory(char c) {
    if (c == 'T') {
        return new StartMezo();
    }
    else if (c == '-') {
        return new UresMezo();
    }
    else if (c == 'X') {
        return new Akadaly();
    }
    else {
        return new Cel(c);
    }
}

/**
* Segedfuggveny, amely megadja, hogy a parameterkent megkapott karakter hexadecimalis karakternek szamit-e.
* (Benne van-e az alabbi betukben: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F})
**/
bool isHexa(char c) {
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70)) {
        return true;
    }
    else {
        return false;
    }
}
/**
* Beolvasast vegzo fuggveny.
* startX: referenciaval atadott argumentum. Ebbe lesz beleirva a start mezonek az x koordinataja.
* startY: referenciaval atadott argumentum. Ebbe lesz beleirva a start mezonek az y koordinataja.
* Return value: pointer a frissen beolvasott es allokalt Terkep objektumra.
**/
Terkep* beolvas(int& startX, int& startY) {
    std::ifstream fbe("input2.txt");
    int n, m;
    std::cin >> n >> m;
    Terkep* terkep = new Terkep(n, m);
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> c;
            if (c == 'T') {
                startX = i;
                startY = j;
            }
            if (isHexa(c)) { // osszegyujtjuk a celmezoknek a koordinatait
                terkep->addCelMezo(i, j);
            }
            terkep->addField(i, j, FieldFactory(c));
        }
    }
    fbe.close();
    return terkep;
}