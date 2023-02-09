#ifndef HAMFUNC_H
#define HAMFUNC_H

#include <string>
#include "Datenbank.h"

Array2d<std::string> getDxccIndex(const std::string& call) {


    enum column {PREFIX, SUFFIX, DXCC_REF, PK_ID};

    const char* basetable {"./../dxcc/src/db/dxcc_basetable.db"};

    Array2d<std::string> ausgabe(1,1,""); // Platzhalter

    std::string prefix {""};
    std::string suffix {""};
    Array2d<std::string> erg(1,1,"");

    try {
        Datenbank db(basetable);

        ausgabe.assign(db.execute("SELECT * FROM prefixes"));

        // ist ein Spezialsuffix enthalten der zur Bestimmung eines DXCC dient?
        for(size_t row=1; row<ausgabe.getZeilen(); ++row) { // Überschrift ausblenden
            if(ausgabe.at(row, SUFFIX) != "") {
                std::string comp {"/" + ausgabe.at(row, SUFFIX)};
                if(call.rfind(comp) == call.length() - comp.length()) {
                    suffix = ausgabe.at(row, SUFFIX);
                    break;
                }
            }
        }

        for(size_t row=1; row<ausgabe.getZeilen(); ++row) {
            if(call.find(ausgabe.at(row, PREFIX)) == 0) {
                prefix = ausgabe.at(row, PREFIX);
            }
        }

        std::string query = "SELECT * FROM prefixes WHERE prefix = \"" + prefix + "\" AND suffix = \"" + suffix + "\";";

        erg.assign(db.execute(query));

    }

    catch (const SQLError& e) {
      std::cerr << e.what() << '\n';
    }

    return erg;
}

#endif // HAMFUNC_H
