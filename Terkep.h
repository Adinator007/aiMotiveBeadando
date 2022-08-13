#pragma once
#include <vector>
#include "Field.h"

class Terkep {
private:
    std::vector<std::pair<int, int>> celMezok; // azon mezok koordinata-parjaik, melyek celmezok.
    int n, m;
    Field*** terep;
    /**
    * Fuggveny, amely ellenorzi, hogy az adott (x, y) koordinata par benne van-e a palyaban.
    **/
    bool ValidKoordinatak(int x, int y) {
        return x >= 0 && x < n&& y >= 0 && y < m;
    }
public:
    Terkep(int n, int m);

    /**
    * Fuggveny, amely berakja az (x, y) koordinataju mezot a sorba, ha az adott mezon meg nem voltunk es onnan tovabb tudunk lepni.
    * (Celmezot nem teszunk bele a sorba, hiszen onnan nem tudunk tovabbhaladni, mert ott vege van az utvonalaknak.)
    **/
    void Berak(int x, int y, std::queue<std::pair<int, int>>& sor);

    /**
    * Fuggveny, amely visszater a celmezok tavolsagainak osszegevel. Ha egy celmezo nem elerheto, akkor a tavolsagot 0-nak veszi.
    **/
    int celMezokTavolsagOsszege();

    /**
    * Fuggveny, amely egy celmezot ad hozza a celmezok listajahoz.
    **/
    void addCelMezo(int x, int y);

    /**
    * Fuggveny, amely egy peldanyositott Field objektumot ad a 2 dimenzios terep egy cellajahoz.
    **/
    void addField(int x, int y, Field* field);

    void setTavolsag(int x, int y, int tav);

    int getTavolsag(int x, int y);

    /**
    * Fuggveny, amely visszater azzal a mezovel, ahova erkezni fogunk, ha az (x, y) mezorol a 'lepes' lepessel haladunk tovabb es beallitja az uj mezonek a tavolsagat.
    * x: az aktualis (, ahonnan lepunk) mezonek az x koordinataja a palyan
    * y: az aktualis (, ahonnan lepunk) mezonek az y koordinataja a palyan
    * lepes: ezzel a lepessel akarunk ellepni az (x, y) koordinataju mezorol
    * tav: az aktualis (, ahonnan lepunk) mezonek a tavolsaga a Start mezotol
    **/
    std::pair<int, int> Leptet(int x, int y, Lepes lepes, int tav);

    ~Terkep();
};