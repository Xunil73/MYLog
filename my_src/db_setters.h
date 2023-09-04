#ifndef DB_SETTERS_H
#define DB_SETTERS_H

#include <string>
#include <vector>
#include "Datenbank.h" // imports all nessassary for Sql operations
#include "hamfunc.h"
#include <fstream>

std::string yyyymmdd(const std::string& ddmmyyyy); // helper to convert dd.mm.yyyy in yyyy-mm-dd
std::string addSeconds(const std::string& tme); // helper to add ":00" to Swisslog-Time to match sqlite3 conv.

struct QsoData {
    std::string prefix {""};
    std::string call {""}; // INSERT OR IGNORE INTO calls - UPPER()
    std::string suffix {""};
    std::string date {""};
    std::string time {""};
    std::string band {""}; // INSERT OR IGNORE INTO bands - UPPER()
    std::string mode {""}; // INSERT OR IGNORE INTO modes - UPPER()
    std::string rstr {""}; // INSERT OR IGNORE INTO rsts
    std::string rsts {""}; // dito
    std::string qslr {""};
    std::string qsls {""};
    std::string locator {""}; // INSERT OR IGNORE INTO locators - UPPER()
    std::string homelocator {""}; // INSERT OR IGNORE INTO homelocators - UPPER()
    std::string homecall {""}; // INSERT OR IGNORE INTO homecalls - UPPER()
    std::string operator_name {""};
    std::string qth {""};
    std::string qslmanager {""}; // INSERT OR IGNORE INTO qsl_managers UPPER()
    std::string repeater {""}; // INSERT OR IGNORE INTO repeaters - UPPER()
    std::string sat {""}; // INSERT OR IGNORE INTO sats - UPPER()
    std::string contest {""};
    std::string remarks {""};
};

/* Der Unterschied isLogImport ist: bei true wird Datum/Zeit als String übernommen
                                         bei false wird es mit den SQL DATE() / TIME() in die DB geschrieben */
void insertQsoToDB(const QsoData& qsoData, bool isLogImport) {

    const char* basetable {"./../dxcc/src/db/dxcc_basetable.db"};

    std::string command =
        "INSERT OR IGNORE INTO calls(call) VALUES('" + qsoData.call + "');" +
        "INSERT OR IGNORE INTO bands(band) VALUES(UPPER('" + qsoData.band + "'));" +
        "INSERT OR IGNORE INTO modes(mode) VALUES(UPPER('" + qsoData.mode + "'));" +
        "INSERT OR IGNORE INTO rsts(rst) VALUES('" + qsoData.rstr + "');" +
        "INSERT OR IGNORE INTO rsts(rst) VALUES('" + qsoData.rsts + "');";
    if(qsoData.locator != "") command += "INSERT OR IGNORE INTO locators(locator) VALUES(UPPER('" + qsoData.locator + "'));";
    if(qsoData.homelocator != "") command += "INSERT OR IGNORE INTO homelocators(homelocator) VALUES(UPPER('" + qsoData.homelocator + "'));";
    if(qsoData.homecall != "") command += "INSERT OR IGNORE INTO homecalls(homecall) VALUES(UPPER('" + qsoData.homecall + "'));";
    if(qsoData.operator_name != "") command += "INSERT OR IGNORE INTO operators(operator) VALUES('" + qsoData.operator_name + "');";
    if(qsoData.qth != "") command += "INSERT OR IGNORE INTO qths(qth) VALUES('" + qsoData.qth + "');";
    if(qsoData.qslmanager != "") command += "INSERT OR IGNORE INTO qsl_managers(qsl_manager) VALUES(UPPER('" + qsoData.qslmanager + "'));";
    if(qsoData.repeater != "") command += "INSERT OR IGNORE INTO repeaters(repeater) VALUES(UPPER('" + qsoData.repeater + "'));";
    if(qsoData.sat != "") command += "INSERT OR IGNORE INTO sats(sat) VALUES(UPPER('" + qsoData.sat + "'));";
    if(qsoData.contest != "") command += "INSERT OR IGNORE INTO contests(contest) VALUES('" + qsoData.contest + "');";

    // add the commands to fill the qso_table with qso-Data
    command += "      \
        INSERT INTO qsos(qso_prefix, qso_call, qso_suffix, qso_date, qso_time, qso_band, qso_mode, qso_rst_r,   \
                         qso_rst_s, qso_qsl_r, qso_qsl_s, qso_locator, qso_homelocator, qso_homecall, qso_operator, \
                         qso_qth, qso_qsl_manager, qso_repeater, qso_sat, qso_contest, qso_remarks)     \
        VALUES (       \
                   (SELECT prefix_id FROM prefixes WHERE prefix = UPPER('" + qsoData.prefix + "'))," +
                  "(SELECT call_id FROM calls WHERE call = UPPER('" + qsoData.call + "'))," +
                   "UPPER('" + qsoData.suffix + "'),";

                            if(isLogImport) command += "'" + qsoData.date + "', '" + qsoData.time + "',";
                            else command += "DATE(), TIME(),";

    command +=    "(SELECT band_id FROM bands WHERE band = UPPER('" + qsoData.band + "'))," +
                  "(SELECT mode_id FROM modes WHERE mode = UPPER('" + qsoData.mode + "'))," +
                  "(SELECT rst_id FROM rsts WHERE rst = '" + qsoData.rstr + "')," +
                  "(SELECT rst_id FROM rsts WHERE rst = '" + qsoData.rsts + "')," +
                  "(SELECT qsl_r_id FROM qsls WHERE qsl_r = '" + qsoData.qslr + "')," +
                  "(SELECT qsl_s_id FROM qsls WHERE qsl_s = '" + qsoData.qsls + "')," +
                  "(SELECT locator_id FROM locators WHERE locator = UPPER('" + qsoData.locator + "'))," +
                  "(SELECT homelocator_id FROM homelocators WHERE homelocator = UPPER('" + qsoData.homelocator + "'))," +
                  "(SELECT homecall_id FROM homecalls WHERE homecall = UPPER('" + qsoData.homecall + "'))," +
                  "(SELECT operator_id FROM operators WHERE operator = '" + qsoData.operator_name + "')," +
                  "(SELECT qth_id FROM qths WHERE qth = '" + qsoData.qth + "')," +
                  "(SELECT qsl_manager_id FROM qsl_managers WHERE qsl_manager = UPPER('" + qsoData.qslmanager + "'))," +
                  "(SELECT repeater_id FROM repeaters WHERE repeater = UPPER('" + qsoData.repeater + "'))," +
                  "(SELECT sat_id FROM sats WHERE sat = UPPER('" + qsoData.sat + "'))," +
                  "(SELECT contest_id FROM contests WHERE contest = '" + qsoData.contest + "'), '" +
                  qsoData.remarks + "');";


}

void importSwisslogCSV(const char* homecall, const char* inputfile) {

    const char* basetable {"./../dxcc/src/db/dxcc_basetable.db"};

    size_t lineindex {1};
    std::ifstream src(inputfile);
    while(src.good()) {
        if(lineindex++ == 1) continue; // Überschrift der CSV überspringen
        std::string inputstr; // nimmt eine Zeile der CSV entgegen
        std::vector<std::string> csvFields; // nimmt die zerlegten Strings von inputstr auf.
        getline(src, inputstr);
        QsoData qsoData;
        std::string substr {""};
        size_t inputstr_index {0};
        while(inputstr_index++ > inputstr.length()) { // das ist möglich da das erste Zeichen des ersten
            if(inputstr.at(inputstr_index) == ';') {  // Substrings ein " ist, das kann übersprungen werden.
                csvFields.push_back(substr);
                substr = "";
            }
            if(inputstr.at(inputstr_index) == '"') continue; // die " werden übersprungen
            substr = substr + inputstr.at(inputstr_index);
        }
        // wir  brauchen nur bestimmte CSV-Daten im Vektor für den Import
        // Achtung! in der CSV kommt erst rsts dann rstr. Deshalb hier der Zuweisungsdreher
        enum Field {CALL, DATE, TIME, BAND, MODE, QSLR, QSLS, RSTR=8, RSTS=7, QTH=9, LOCATOR=10,
                           REMARKS=11; OPERATOR_NAME=12, QSLMANAGER=15};

        /* Strategie:
           Nun Zerlegen wir das Call mit splitCall() aus hamfunc.h und speichern alle Teile des Vectors in
           dem Struct. Wir müssen noch das Datumformat drehen. Der Eingabestrom aus der CSV muss noch
           geschlossen werden. Zuletzt wird das Struct in die Datenbanktabelle "qsos" gespeichert.
           Dazu wird eine qsos-table-setter-funktion geschrieben die das Struct in die DB einfügt.
           Das Struct muss noch um die fehlenden Spalten der qsos-table ergänzt werden.
        */

        // we fill the qsoData struct:
        Array2d<std::string> callsign(1,1,"");
        callsign = splitCall(csvFields.at(Field::CALL));
        qsoData.prefix = callsign.at(1,1); // using upper in SQL-Statement
        qsoData.call = callsign.at(1,2);   // dito
        qsoData.suffix = callsign.at(1,3); // dito
        qsoData.date = yyyymmdd(csvFields.at(Field::DATE));
        qsoData.time = addSeconds(csvFields.at(Field::TIME));
        qsoData.band = csvFields.at(Field::BAND); // Format: 80m - using upper in SQL statement to get 80M
        qsoData.mode = csvFields.at(Field::MODE); // is upper in src file
        if(csvFields.at(Field::QSLR) == "0") qsoData.qslr = "NO";
        else qsoData.qslr = "YES";
        if(csvFields.at(Field::QSLS) == "0") qsoData.qsls = "NO";
        else qsoData.qsls = "YES";
        qsoData.rstr = csvFields.at(Field::RSTR);
        qsoData.rsts = csvFields.at(Field::RSTS);
        qsoData.qth = csvFields.at(Field::QTH);
        qsoData.locator = csvFields.at(Field::LOCATOR); // using upper in SQL statement
        qsoData.remarks = csvFields.at(Field::REMARKS);
        qsoData.operator_name = csvFields.at(Field::OPERATOR_NAME);
        qsoData.qslmanager = csvFields.at(Field::QSLMANAGER); // using upper in SQL statement

        qsoData.homecall = homecall;

    }

}

// Datumskonvertierung DD-MM-YYYY -> YYYY-MM-DD
std::string yyyymmdd(const std::string& ddmmyyyy) {
    std::string dd ;
    std::string mm;
    std::string yyyy;
    dd.assign(ddmmyyyy, 0, 2);
    mm.assign(ddmmyyyy, 3, 2);
    yyyy.assign(ddmmyyyy, 6, 4);
    return yyyy + '-' + mm + '-' + dd;
}

std::string addSeconds(const std::string& tme) {
    return tme + ":00";
}
#endif // DB_SETTERS_H
