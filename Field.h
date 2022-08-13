#pragma once
#include <queue>
#include "Lepes.h"
class Field {
protected:
    int tav; // tavolsag a StartMezo-tol
public:

    Field();

    /**
    return value: azzal ter vissza, hogy a tavolsag szerint szabad-e erre a mezore lepni. Ha voltunk mar egy mezon, akkor oda mar nem lephetunk vissza. (BFS logika miatt.)
    **/
    bool validateTavolsag();
    void setTavolsag(int tav);
    int getTavolsag();

    /**
    * Tisztan virtualis fuggveny, ami azzal ter vissza, hogy az adott lepessel be lehet-e lepni ebbe a mezobe. (Ha a mezo nyitott jobb oldalrol,
    * akkor 'Bal' lepesre ter vissza true-val)
    **/
    virtual bool Accept(Lepes lepes) = 0;

    /**
    Tisztan virtualis fuggveny, ami az (x, y) koordinatakat beleteszi a sorba, ha olyan mezo az aktualis, amirol tovabb lehet lepni.
    A BFS-algoritmus hasznalja.
    **/
    virtual void Berak(int x, int y, std::queue<std::pair<int, int>>& sor) = 0; // azert nincs az (x, y) koordinata eltarolva a Field osztalyban, hogy
    // ezzel ne kosusk meg a Field felelossegi koret. Igy pl konnyebben tudjuk boviteni a szoftvert egy altalanos grafos palyareprezentaciora
};
