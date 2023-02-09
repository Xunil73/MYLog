/* cppbuch/k18/Datenbank.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/
*/
#ifndef DATENBANK_H
#define DATENBANK_H
#include "array2d.h"
#include <sqlite3.h>
#include <stdexcept>
#include <string>

struct SQLError : public std::runtime_error {
  SQLError(const std::string& msg)
      : std::runtime_error(std::string("SQL-Fehler: ") + msg) {}
};

class Datenbank {
public:
  Datenbank(const char* dateiname) : db(0) {
    if (sqlite3_open(dateiname, &db) != SQLITE_OK) {  // Fehler?
      const char* fehlermeldung = sqlite3_errmsg(db);
      sqlite3_close(db);
      throw SQLError(fehlermeldung);
    }
  }

  ~Datenbank() { sqlite3_close(db); }

  Array2d<std::string> execute(const std::string& sqlAnweisung) const {
    // 4 Variable zur Speicherung des Ergebnisses aus
    // sqlite3_get_table()
    char* fehlermeldung = 0;
    int zeilen;   // muss int sein wegen sqlite3_get_table
    int spalten;  // dito
    char** cstringarray = 0;
    int erg = sqlite3_get_table(db, sqlAnweisung.c_str(),
                                &cstringarray,  // Tabelle
                                &zeilen, &spalten, &fehlermeldung);
    Array2d<std::string> ergebnis(1, 1, "");  // Platzhalter
    if (erg != SQLITE_OK) {                   // Fehler?
      std::string msg(fehlermeldung);
      sqlite3_free(fehlermeldung);  // Freigaben nicht vergessen!
      sqlite3_free_table(cstringarray);
      throw SQLError(msg);
    } else {
      if (zeilen > 0) {  // Zeilen einsammeln, eine mehr fuer die Ueberschrift
        ergebnis.assign(Array2d<std::string>(++zeilen, spalten));
        for (int z = 0; z < zeilen; ++z) {
          for (int s = 0; s < spalten; ++s) {
            // NULL-Einträge berücksichtigen
            const char* str = cstringarray[z * spalten + s];
            ergebnis.at(z,s) = str ? str : "";
          }
        }
      }
      sqlite3_free_table(cstringarray);  // Freigabe nicht vergessen!
    }
    return ergebnis;
  }

private:
  sqlite3* db;
  Datenbank(const Datenbank&) = delete;  // soll nicht kopiert werden
  Datenbank&
  operator=(const Datenbank&) = delete;  // soll nicht zugewiesen werden
};
#endif
