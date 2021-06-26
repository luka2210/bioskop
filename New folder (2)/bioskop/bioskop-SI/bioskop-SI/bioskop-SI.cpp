#include <iostream>
#include <string>
#include <fstream>

#include "Zaposleni.h"
#include "Sala.h"
#include "Film.h"
#include "Gledalac.h"

using namespace std;

int izaberiRolu() {
    int izabranaOpcija;

    cout << "-------------------------------------------------\n\n";
    cout << "Pocetna stranica\n\n\n";

    cout << "Izaberite koju rolu zelite da koristite:\n\n";
    cout << "1) Zaposleni\n";
    cout << "2) Gledalac\n\n";

    cout << "0) Napusti program\n\n";

    cout << "-------------------------------------------------\n\n";

    do {
        cout << "Izaberite jednu od ponudjenih opcija: ";
        cin >> izabranaOpcija;
    } while (izabranaOpcija < 0 || izabranaOpcija > 2);

    return izabranaOpcija;
}

int izlistajZaposlene(Zaposleni* z, int len) {
    int izabraniRadnik, izabranaOpcija;

    cout << "Izaberite jednog od ponudjenog zaposlenog!\n\n";

    cout << "ID               IME              PREZIME\n\n";

    for (int i = 0; i < len; i++) {
        cout << i+1 << ") " << z[i].id << "            " << z[i].ime << "              " << z[i].prezime << endl;
    }

    cout << "\n0) Napusti program";

    cout << "\n\n";

    do {
        cout << "Izaberite jednu od ponudjenih opcija: ";
        cin >> izabraniRadnik;
    } while (izabraniRadnik < 0 || izabraniRadnik > len);

    if(izabraniRadnik != 0) cout << "Izabrali ste radnika sa ID-jem " << z[izabraniRadnik - 1].id << " koji se zove " << z[izabraniRadnik - 1].ime << " " << z[izabraniRadnik - 1].prezime << "\n\n";

    cout << "-------------------------------------------------\n\n";

    cout << "Dozvoljene opcije za zaposlene\n\n";

    cout << "1) Dodaj film\n";
    cout << "2) Obrisi film\n\n";
    cout << "0) Napusti program\n\n";

    cout << "-------------------------------------------------\n\n";

    do {
        cout << "Izaberite jednu od ponudjenih opcija: ";
        cin >> izabranaOpcija;
    } while (izabranaOpcija < 0 || izabranaOpcija > 2);

    return izabranaOpcija;
}

Gledalac izlistajGledaoce(Gledalac *g, int len) {
    Gledalac gledalac;
    int izabraniGledalac;

    cout << "Izaberite jednog od ponudjenih gledalaca!\n\n";

    cout << "UERNAME               SIFRA              EMAIL\n\n";

    for (int i = 0; i < len; i++) {
        cout << i + 1 << ") " << g[i].username << "            " << g[i].sifra << "              " << g[i].email << endl;
    }

    cout << "\n0) Napusti program";

    cout << "\n\n";

    do {
        cout << "Izaberite jednu od ponudjenih opcija: ";
        cin >> izabraniGledalac;
    } while (izabraniGledalac < 0 || izabraniGledalac > len);

    gledalac = g[izabraniGledalac - 1];

    return gledalac;
}

/*void dodajFilm() {
    int idFilma, salaFilma;
    string nazivFilma;

    cout << "U ovoj sekciji dodajete film!\n\n";

    cout << "Unesite ID filma: ";
    cin >> idFilma;

    cout << "\nUnesite naziv filma: ";
    cin >> nazivFilma;

    cout << "\nUnesite ID sale gde ce se film projektovati: ";
    cin >> salaFilma;

    cout << "\n\nDodali ste film sa ID-jem " << idFilma << " pod nazivom " << nazivFilma << " koji se projektuje u sali sa ID-jem " << salaFilma << endl;
}*/

void izlistajFilmove(Film* filmovi, int len) {

    cout << "ID FILMA           " << "          NAZIV           " << "ID SALE\n\n";

    for (int i = 0; i < len; i++) {
        cout << i+1 << ") " << filmovi[i].id << "                      " << filmovi[i].naziv << "          " << filmovi[i].sala << endl;
    }

    cout << "\n0) Napusti program" << endl;
}

/*void izbrisiFilm(Film* filmovi, int len) {
    int obrisanFilm;

    do {
        cout << "\n\nIzaberite jedan od ponudjenih filmova koji zelite da obrisete: ";
        cin >> obrisanFilm;
    } while (obrisanFilm < 0 && obrisanFilm > len);

    if (obrisanFilm != 0) {
        cout << "\n\nObrisali ste film sa ID-jem " << filmovi[obrisanFilm - 1].id << " pod nazivom " << filmovi[obrisanFilm - 1].naziv << " koji se prikazuje u sali sa ID-jem " << filmovi[obrisanFilm - 1].sala << "\n\n";
    }
}*/

Film izaberiFilm(Film *filmovi, int len) {
    int izabrani;

    do {
        cout << "\n\nIzaberite jedan od ponudjenih filmova za koji zelite da rezervisete karte: ";
        cin >> izabrani;
    } while (izabrani < 0 && izabrani > len);

    if (izabrani != 0) {
        cout << "\n-------------------------------------------------\n\n";
        cout << "Ovde rezervisite karte za film sa ID-jem " << filmovi[izabrani - 1].id << " pod nazivom " << filmovi[izabrani - 1].naziv << " u sali sa ID-jem " << filmovi[izabrani - 1].sala << endl;
    }

    return filmovi[izabrani-1];
}

void salaInformacije(Gledalac g, Film f, Sala s, int brTermina) {
    int termin, brKarata;
    ofstream myfile;

    cout << "\nBroj slobodnih mesta u sali: " << s.brojSlobodnihMesta << "\n";
    cout << "\nSala u kojoj se projektuje film ima sledece termine\n\n";

    for (int i = 0; i < brTermina; i++) {
        cout << i + 1 << ") " << s.termini[i] << endl;
    }

    cout << "\n0) Napusti program\n\n";

    cout << "-------------------------------------------------\n\n";

    do {
        cout << "\n\nIzaberite jedan od ponudjenih termin za film za koji zelite da rezervisete: ";
        cin >> termin;
    } while (termin < 0 || termin > brTermina);

    if (termin != 0) {
        do {
            cout << "\nUnesite koliko karata zelite da rezervisete - broj karata ne moze biti jednak ili manji od 0 i veci od 10: ";
            cin >> brKarata;
        } while (brKarata <= 0 || brKarata > 10);

        if (brKarata > s.brojSlobodnihMesta) {
            cout << "NEMA SLOBODNIH MESTA!\n\n";
        }
        else {
            myfile.open("rezervacija.out");
            myfile << "-------------------------------------------------\n\n";
            myfile << "Poslato na mejl gledaocu: " << g.email << "\n\n";
            myfile << "Film za koji su rezervisane karte: " << f.naziv << "\n\n";
            myfile << "Termin projekcije je: " << s.termini[termin-1] << "\n\n";
            myfile << "Broj rezervisanih karata je: " << brKarata << "\n\n";
            myfile << "Vas broj rezervacije je: " << rand() % 1000 << "\n\n";
            myfile << "-------------------------------------------------";
            myfile.close();
        }
    }

}

Film* dodajFilm(Film *filmovi, int &br_filmova) {
    Film *novi_filmovi = new Film[++br_filmova];
    for (int i = 0; i < br_filmova - 1; i++) novi_filmovi[i] = filmovi[i];
    cin >> novi_filmovi[br_filmova - 1].id >> novi_filmovi[br_filmova - 1].naziv >> novi_filmovi[br_filmova - 1].sala;
    delete[] filmovi;
    return novi_filmovi;
}

void izbrisiFilm(Film *filmovi, int &br_filmova) {
    int id_brisi;
    cin >> id_brisi;
    for (int i = 0; i < br_filmova; i++) if (filmovi[i].id == id_brisi) {
        for (int j = i; j < br_filmova - 1; j++) filmovi[j] = filmovi[j + 1];
        --br_filmova;
    }
}

void stampajFilmove(Film *filmovi, int br_filmova) {
    for (int i = 0; i < br_filmova; i++)
        cout << filmovi[i].id << ' ' << filmovi[i].naziv << ' ' << filmovi[i].sala << endl;
}

int main()
{
    ofstream myfile;

    int br_filmova = 3;
    Film *filmovi = new Film[br_filmova];

    int filmId[3] = { 1, 2, 3 };
    string naziv[3] = { "Harry Potter", "Home Alone", "Tokio Drift" };
    int sala[3] = { 4, 3, 5 };


    for (int i = 0; i < 3; i++) {
        filmovi[i] = Film(filmId[i], naziv[i], sala[i]);
    }

    // ovde sam samo testirao kako radi
    /*filmovi = dodajFilm(filmovi, br_filmova);
    stampajFilmove(filmovi, br_filmova);

    izbrisiFilm(filmovi, br_filmova);
    stampajFilmove(filmovi, br_filmova);

    return 0;*/
    //

    Sala salaUKojojSePusta;
    int rola;
    int opcija;
    Gledalac gledalac;
    Film izabraniFilm;

    Zaposleni radnici[4];
    string imenaRadnika[4] = { "Milena", "Milica", "Darko", "Laza" };
    string prezimenaRadnika[4] = { "Milic", "Lazic", "Radovic", "Krsmanovic" };
    for (int i = 0; i < 4; i++) {
        radnici[i] = Zaposleni(imenaRadnika[i], prezimenaRadnika[i]);
    }

    Gledalac gledaoci[4];
    string username[4] = { "mihailo98", "jovan", "derr", "milica" };
    string sifra[4] = { "12345", "jo99", "banana48", "cpls" };
    string email[4] = { "mih@gmail.com", "j99@gmail.com", "ddrr@gmail.com", "milicam@gmail.com" };

    for (int i = 0; i < 4; i++) {
        gledaoci[i] = Gledalac(username[i], sifra[i], email[i]);
    }

    string termini[3] = { "20h", "21:30h", "23h" };
    int salaId[3] = { 1, 2, 3 };
    int brojMesta[3] = { 5, 3, 5 };
    Sala sale[3];

    for (int i = 0; i < 3; i++) {
        sale[i] = Sala(salaId[i], termini, brojMesta[i]);
    }

    rola = izaberiRolu();
    if (rola == 0) cout << "Dovidjenja!" << endl;

    else if (rola == 1) {
        opcija = izlistajZaposlene(radnici, 4);

        if (opcija == 1) {
            filmovi = dodajFilm(filmovi, br_filmova);
            izlistajFilmove(filmovi, br_filmova);
        }
        else if (opcija == 2) {
            cout << "Odaberite koji film zelite da izbrisete!\n\n";
            izlistajFilmove(filmovi, br_filmova);
            izbrisiFilm(filmovi, br_filmova);
        }
    }
    else if (rola == 2) {
        gledalac = izlistajGledaoce(gledaoci, 4);

        izlistajFilmove(filmovi, 3);
        izabraniFilm = izaberiFilm(filmovi, 3);
        if (izabraniFilm.id != 0) {
            for (int i = 0; i < 3; i++) {
                if (sale[i].id = izabraniFilm.id) {
                    salaUKojojSePusta = sale[i];
                    break;
                }
            }

            salaInformacije(gledalac, izabraniFilm, salaUKojojSePusta, 3);
            
        }

    }

    else if (rola == 2) cout << "Izabrali ste gledaoca!" << endl;

    return 0;
} 