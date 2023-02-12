#ifndef HAMFUNC_H
#define HAMFUNC_H

#include <string>
#include "Datenbank.h"

Array2d<std::string> getDxccRefIDs(const std::string& call) {

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

        std::string query = "SELECT dxcc_ref_id FROM prefixes WHERE prefix = \"" + prefix + "\" AND suffix = \"" + suffix + "\";";

        erg.assign(db.execute(query));

    }

    catch (const SQLError& e) {
      std::cerr << e.what() << '\n';
    }

    return erg;
}



Array2d<std::string> getFullDxccInfos(const std::string& call) {

    Array2d<std::string> dxccIndex(1,1,"");
    dxccIndex.assign(getDxccRefIDs(call));


    std::string query = "SELECT countries.dxcc_name, continents.continent_name, \
                                cq_zones.cq_zone, itu_zones.itu_zone FROM countries \
                                JOIN continents ON continents.dxcc_ref_id = countries.dxcc_ref_id \
                                JOIN cq_zones ON cq_zones.dxcc_ref_id = continents.dxcc_ref_id \
                                JOIN itu_zones ON itu_zones.dxcc_ref_id = continents.dxcc_ref_id \
                         WHERE countries.dxcc_ref_id = ";


    if(dxccIndex.getZeilen() > 1) {
        for(size_t row=1; row<dxccIndex.getZeilen(); ++row) {
            std::string temp = "\"" + dxccIndex.at(row,0) + "\"";
            if(row == 1) query += temp;
            if(row > 1) query += (" OR countries.dxcc_ref_id = " + temp);
        }
        query += ";";
    }

    else query = "";


    Array2d<std::string> fullDxccInfo(1,1,"");

    try {
        const char* basetable {"./../dxcc/src/db/dxcc_basetable.db"};
        Datenbank db(basetable);
        fullDxccInfo.assign(db.execute(query));
    }
    catch (const SQLError& e) {
      std::cerr << e.what() << '\n';
    }

    return fullDxccInfo;
}



Array2d<std::string> getCqZoneInfos(const std::string& call) {

    Array2d<std::string> dxccIndex(1,1,"");
    dxccIndex.assign(getDxccRefIDs(call));

    std::string query = "SELECT DISTINCT cq_zone FROM cq_zones \
                         WHERE dxcc_ref_id = ";

    if(dxccIndex.getZeilen() > 1) {
        for(size_t row=1; row<dxccIndex.getZeilen(); ++row) {
            std::string temp = "\"" + dxccIndex.at(row,0) + "\"";
            if(row == 1) query += temp;
            if(row > 1) query += (" OR dxcc_ref_id = " + temp);
        }
        query += ";";
    }

    else query = "";

    Array2d<std::string> cqZoneInfos(1,1,"");

    try {
        const char* basetable {"./../dxcc/src/db/dxcc_basetable.db"};
        Datenbank db(basetable);
        cqZoneInfos.assign(db.execute(query));
    }
    catch (const SQLError& e) {
      std::cerr << e.what() << '\n';
    }

    return cqZoneInfos;

}


Array2d<std::string> getItuZoneInfos(const std::string& call) {

    Array2d<std::string> dxccIndex(1,1,"");
    dxccIndex.assign(getDxccRefIDs(call));

    std::string query = "SELECT DISTINCT itu_zone FROM itu_zones \
                         WHERE dxcc_ref_id = ";

    if(dxccIndex.getZeilen() > 1) {
        for(size_t row=1; row<dxccIndex.getZeilen(); ++row) {
            std::string temp = "\"" + dxccIndex.at(row,0) + "\"";
            if(row == 1) query += temp;
            if(row > 1) query += (" OR dxcc_ref_id = " + temp);
        }
        query += ";";
    }

    else query = "";

    Array2d<std::string> ituZoneInfos(1,1,"");

    try {
        const char* basetable {"./../dxcc/src/db/dxcc_basetable.db"};
        Datenbank db(basetable);
        ituZoneInfos.assign(db.execute(query));
    }
    catch (const SQLError& e) {
      std::cerr << e.what() << '\n';
    }

    return ituZoneInfos;

}
#endif // HAMFUNC_H
