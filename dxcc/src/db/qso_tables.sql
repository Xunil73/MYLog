CREATE TABLE calls (
    call_id INTEGER PRIMARY KEY AUTOINCREMENT,
    call VARCHAR(15) UNIQUE
);

CREATE TABLE bands(
    band_id INTEGER PRIMARY KEY AUTOINCREMENT,
    band VARCHAR(8) UNIQUE
);

CREATE TABLE modes (
    mode_id INTEGER PRIMARY KEY AUTOINCREMENT,
    mode VARCHAR(10)
);

CREATE TABLE qsl_r (
    qsl_r_id INTEGER PRIMARY KEY AUTOINCREMENT,
    qsl_r_status VARCHAR(3)
);

CREATE TABLE qsl_s (
    qsl_s_id INTEGER PRIMARY KEY AUTOINCREMENT,
    qsl_s_status VARCHAR(4)
);

CREATE TABLE homecalls (
    homecall_id INTEGER PRIMARY KEY AUTOINCREMENT,
    homecall VARCHAR(16)
);

CREATE TABLE homelocators (
    homelocator_id INTEGER PRIMARY KEY AUTOINCREMENT,
    homelocator VARCHAR(6)
);

CREATE TABLE rsts (
    rst_id INTEGER PRIMARY KEY AUTOINCREMENT,
    rst VARCHAR(25)
);

CREATE TABLE locators (
    locator_id INTEGER PRIMARY KEY AUTOINCREMENT,
    locator VARCHAR(6)
);

CREATE TABLE operators (
    operator_id INTEGER PRIMARY KEY AUTOINCREMENT,
    operator VARCHAR(15)
);

CREATE TABLE qths (
    qth_id INTEGER PRIMARY KEY AUTOINCREMENT,
    qth VARCHAR(15)
);

CREATE TABLE qsl_managers (
    qsl_manager_id INTEGER PRIMARY KEY AUTOINCREMENT,
    qsl_manager VARCHAR(12)
);

CREATE TABLE repeaters (
    repeater_id INTEGER PRIMARY KEY AUTOINCREMENT,
    repeater VARCHAR(10)
);

CREATE TABLE sats (
    sat_id INTEGER PRIMARY KEY AUTOINCREMENT,
    sat_name VARCHAR(10),
    sat_mode VARCHAR (6)
);

CREATE TABLE contests (
    contest_id INTEGER PRIMARY KEY AUTOINCREMENT,
    contest VARCHAR(20)
);

CREATE TABLE qsos (
    qso_id INTEGER PRIMARY KEY AUTOINCREMENT,
    qso_prefix INTEGER,
    qso_call INTEGER,
    qso_suffix VARCHAR(7),
    qso_date VARCHAR(10),
    qso_time VARCHAR(5),
    qso_band INTEGER,
    qso_mode INTEGER,
    qso_rst_r INTEGER,
    qso_rst_s INTEGER,
    qso_qsl_r INTEGER,
    qso_qsl_s INTEGER,
    qso_locator INTEGER,
    qso_homelocator INTEGER,
    qso_homecall INTEGER,
    qso_operator INTEGER,
    qso_qth INTEGER,
    qso_qsl_manager INTEGER,
    qso_repeater INTEGER,
    qso_sat INTEGER,
    qso_contest INTEGER,
    qso_remarks VARCHAR(1500),
    FOREIGN KEY (qso_prefix) REFERENCES prefixes (prefix_id),
    FOREIGN KEY (qso_call) REFERENCES calls (call_id),
    FOREIGN KEY (qso_band) REFERENCES bands (band_id),
    FOREIGN KEY (qso_mode) REFERENCES modes (mode_id),
    FOREIGN KEY (qso_rst_r) REFERENCES rsts (rst_id),
    FOREIGN KEY (qso_rst_s) REFERENCES rsts (rst_id),
    FOREIGN KEY (qso_qsl_r) REFERENCES qsl_r (qsl_r_id),
    FOREIGN KEY (qso_qsl_s) REFERENCES qsl_s (qsl_s_id),
    FOREIGN KEY (qso_locator) REFERENCES locators (locator_id),
    FOREIGN KEY (qso_homelocator) REFERENCES homelocators (homelocator_id),
    FOREIGN KEY (qso_homecall) REFERENCES homecalls (homecall_id),
    FOREIGN KEY (qso_operator) REFERENCES operators (operator_id),
    FOREIGN KEY (qso_qth) REFERENCES qths (qth_id),
    FOREIGN KEY (qso_qsl_manager) REFERENCES qsl_managers (qsl_manager_id),
    FOREIGN KEY (qso_repeater) REFERENCES repeaters (repeater_id),
    FOREIGN KEY (qso_sat) REFERENCES sats (sat_id),
    FOREIGN KEY (qso_contest) REFERENCES contests (contest_id)
);


INSERT INTO bands (band) VALUES ("2200M");
INSERT INTO bands (band) VALUES ("630M");
INSERT INTO bands (band) VALUES ("160M");
INSERT INTO bands (band) VALUES ("80M");
INSERT INTO bands (band) VALUES ("60M");
INSERT INTO bands (band) VALUES ("40M");
INSERT INTO bands (band) VALUES ("30M");
INSERT INTO bands (band) VALUES ("20M");
INSERT INTO bands (band) VALUES ("17M");
INSERT INTO bands (band) VALUES ("15M");
INSERT INTO bands (band) VALUES ("12M");
INSERT INTO bands (band) VALUES ("10M");
INSERT INTO bands (band) VALUES ("6M");
INSERT INTO bands (band) VALUES ("4M");
INSERT INTO bands (band) VALUES ("2M");
INSERT INTO bands (band) VALUES ("70CM");
INSERT INTO bands (band) VALUES ("23CM");
INSERT INTO bands (band) VALUES ("13CM");
INSERT INTO bands (band) VALUES ("9CM");
INSERT INTO bands (band) VALUES ("6CM");
INSERT INTO bands (band) VALUES ("3CM");
INSERT INTO bands (band) VALUES ("12MM");
INSERT INTO bands (band) VALUES ("6MM");
INSERT INTO bands (band) VALUES ("4MM");

INSERT INTO modes (mode) VALUES ("CW");
INSERT INTO modes (mode) VALUES ("LSB");
INSERT INTO modes (mode) VALUES ("USB");
INSERT INTO modes (mode) VALUES ("AM");
INSERT INTO modes (mode) VALUES ("FM");
INSERT INTO modes (mode) VALUES ("RTTY");
INSERT INTO modes (mode) VALUES ("SSTV");
INSERT INTO modes (mode) VALUES ("HELL");
INSERT INTO modes (mode) VALUES ("CONTESTIA");
INSERT INTO modes (mode) VALUES ("DOMINOEX");
INSERT INTO modes (mode) VALUES ("FSQ");
INSERT INTO modes (mode) VALUES ("IFKP");
INSERT INTO modes (mode) VALUES ("MFSK");
INSERT INTO modes (mode) VALUES ("MT63");
INSERT INTO modes (mode) VALUES ("OLIVIA");
INSERT INTO modes (mode) VALUES ("PSK");
INSERT INTO modes (mode) VALUES ("QPSK");
INSERT INTO modes (mode) VALUES ("8PSK");
INSERT INTO modes (mode) VALUES ("PSKR");
INSERT INTO modes (mode) VALUES ("THOR");
INSERT INTO modes (mode) VALUES ("THROB");
INSERT INTO modes (mode) VALUES ("WEFAX");
INSERT INTO modes (mode) VALUES ("NAVTEX");

INSERT INTO qsl_r (qsl_r_status) VALUES ("NO");
INSERT INTO qsl_r (qsl_r_status) VALUES ("YES");

INSERT INTO qsl_s (qsl_s_status) VALUES ("NO");
INSERT INTO qsl_s (qsl_s_status) VALUES ("SEND");
INSERT INTO qsl_s (qsl_s_status) VALUES ("YES");
INSERT INTO qsl_s (qsl_s_status) VALUES ("DIRECT");

INSERT INTO homecalls (homecall) VALUES ("DO1MHS");
INSERT INTO homecalls (homecall) VALUES ("DO1MHS/P");
INSERT INTO homecalls (homecall) VALUES ("DO1MHS/M");
INSERT INTO homecalls (homecall) VALUES ("DB2MQ");
INSERT INTO homecalls (homecall) VALUES ("DB2MQ/P");
INSERT INTO homecalls (homecall) VALUES ("DB2MQ/M");
INSERT INTO homecalls (homecall) VALUES ("DJ5MY");
INSERT INTO homecalls (homecall) VALUES ("DJ5MY/P");
INSERT INTO homecalls (homecall) VALUES ("DJ5MY/M");

INSERT INTO homelocators (homelocator) VALUES ("JN68CB");
INSERT INTO homelocators (homelocator) VALUES ("JN58BI");
INSERT INTO homelocators (homelocator) VALUES ("JN58VF");
INSERT INTO homelocators (homelocator) VALUES ("JN67CU");

INSERT INTO rsts (rst) VALUES ("59");
INSERT INTO rsts (rst) VALUES ("58");
INSERT INTO rsts (rst) VALUES ("57");
INSERT INTO rsts (rst) VALUES ("56");
INSERT INTO rsts (rst) VALUES ("55");
INSERT INTO rsts (rst) VALUES ("54");
INSERT INTO rsts (rst) VALUES ("53");
INSERT INTO rsts (rst) VALUES ("52");
INSERT INTO rsts (rst) VALUES ("51");
INSERT INTO rsts (rst) VALUES ("49");
INSERT INTO rsts (rst) VALUES ("48");
INSERT INTO rsts (rst) VALUES ("47");
INSERT INTO rsts (rst) VALUES ("46");
INSERT INTO rsts (rst) VALUES ("45");
INSERT INTO rsts (rst) VALUES ("44");
INSERT INTO rsts (rst) VALUES ("43");
INSERT INTO rsts (rst) VALUES ("42");
INSERT INTO rsts (rst) VALUES ("41");
INSERT INTO rsts (rst) VALUES ("39");
INSERT INTO rsts (rst) VALUES ("38");
INSERT INTO rsts (rst) VALUES ("37");
INSERT INTO rsts (rst) VALUES ("36");
INSERT INTO rsts (rst) VALUES ("35");
INSERT INTO rsts (rst) VALUES ("34");
INSERT INTO rsts (rst) VALUES ("33");
INSERT INTO rsts (rst) VALUES ("32");
INSERT INTO rsts (rst) VALUES ("31");
INSERT INTO rsts (rst) VALUES ("29");
INSERT INTO rsts (rst) VALUES ("28");
INSERT INTO rsts (rst) VALUES ("27");
INSERT INTO rsts (rst) VALUES ("26");
INSERT INTO rsts (rst) VALUES ("25");
INSERT INTO rsts (rst) VALUES ("24");
INSERT INTO rsts (rst) VALUES ("23");
INSERT INTO rsts (rst) VALUES ("22");
INSERT INTO rsts (rst) VALUES ("21");
INSERT INTO rsts (rst) VALUES ("19");
INSERT INTO rsts (rst) VALUES ("18");
INSERT INTO rsts (rst) VALUES ("17");
INSERT INTO rsts (rst) VALUES ("16");
INSERT INTO rsts (rst) VALUES ("15");
INSERT INTO rsts (rst) VALUES ("14");
INSERT INTO rsts (rst) VALUES ("13");
INSERT INTO rsts (rst) VALUES ("12");
INSERT INTO rsts (rst) VALUES ("11");
INSERT INTO rsts (rst) VALUES ("599");
INSERT INTO rsts (rst) VALUES ("589");
INSERT INTO rsts (rst) VALUES ("579");
INSERT INTO rsts (rst) VALUES ("569");
INSERT INTO rsts (rst) VALUES ("559");
INSERT INTO rsts (rst) VALUES ("549");
INSERT INTO rsts (rst) VALUES ("539");
INSERT INTO rsts (rst) VALUES ("529");
INSERT INTO rsts (rst) VALUES ("519");
INSERT INTO rsts (rst) VALUES ("499");
INSERT INTO rsts (rst) VALUES ("489");
INSERT INTO rsts (rst) VALUES ("479");
INSERT INTO rsts (rst) VALUES ("469");
INSERT INTO rsts (rst) VALUES ("459");
INSERT INTO rsts (rst) VALUES ("449");
INSERT INTO rsts (rst) VALUES ("439");
INSERT INTO rsts (rst) VALUES ("429");
INSERT INTO rsts (rst) VALUES ("419");
INSERT INTO rsts (rst) VALUES ("399");
INSERT INTO rsts (rst) VALUES ("389");
INSERT INTO rsts (rst) VALUES ("379");
INSERT INTO rsts (rst) VALUES ("369");
INSERT INTO rsts (rst) VALUES ("359");
INSERT INTO rsts (rst) VALUES ("349");
INSERT INTO rsts (rst) VALUES ("339");
INSERT INTO rsts (rst) VALUES ("329");
INSERT INTO rsts (rst) VALUES ("319");
INSERT INTO rsts (rst) VALUES ("299");
INSERT INTO rsts (rst) VALUES ("289");
INSERT INTO rsts (rst) VALUES ("279");
INSERT INTO rsts (rst) VALUES ("269");
INSERT INTO rsts (rst) VALUES ("259");
INSERT INTO rsts (rst) VALUES ("249");
INSERT INTO rsts (rst) VALUES ("239");
INSERT INTO rsts (rst) VALUES ("229");
INSERT INTO rsts (rst) VALUES ("219");
INSERT INTO rsts (rst) VALUES ("199");
INSERT INTO rsts (rst) VALUES ("189");
INSERT INTO rsts (rst) VALUES ("179");
INSERT INTO rsts (rst) VALUES ("169");
INSERT INTO rsts (rst) VALUES ("159");
INSERT INTO rsts (rst) VALUES ("149");
INSERT INTO rsts (rst) VALUES ("139");
INSERT INTO rsts (rst) VALUES ("129");
INSERT INTO rsts (rst) VALUES ("119");
INSERT INTO rsts (rst) VALUES ("598");
INSERT INTO rsts (rst) VALUES ("588");
INSERT INTO rsts (rst) VALUES ("578");
INSERT INTO rsts (rst) VALUES ("568");
INSERT INTO rsts (rst) VALUES ("558");
INSERT INTO rsts (rst) VALUES ("548");
INSERT INTO rsts (rst) VALUES ("538");
INSERT INTO rsts (rst) VALUES ("528");
INSERT INTO rsts (rst) VALUES ("518");
INSERT INTO rsts (rst) VALUES ("498");
INSERT INTO rsts (rst) VALUES ("488");
INSERT INTO rsts (rst) VALUES ("478");
INSERT INTO rsts (rst) VALUES ("468");
INSERT INTO rsts (rst) VALUES ("458");
INSERT INTO rsts (rst) VALUES ("448");
INSERT INTO rsts (rst) VALUES ("438");
INSERT INTO rsts (rst) VALUES ("428");
INSERT INTO rsts (rst) VALUES ("418");
INSERT INTO rsts (rst) VALUES ("398");
INSERT INTO rsts (rst) VALUES ("388");
INSERT INTO rsts (rst) VALUES ("378");
INSERT INTO rsts (rst) VALUES ("368");
INSERT INTO rsts (rst) VALUES ("358");
INSERT INTO rsts (rst) VALUES ("348");
INSERT INTO rsts (rst) VALUES ("338");
INSERT INTO rsts (rst) VALUES ("328");
INSERT INTO rsts (rst) VALUES ("318");
INSERT INTO rsts (rst) VALUES ("298");
INSERT INTO rsts (rst) VALUES ("288");
INSERT INTO rsts (rst) VALUES ("278");
INSERT INTO rsts (rst) VALUES ("268");
INSERT INTO rsts (rst) VALUES ("258");
INSERT INTO rsts (rst) VALUES ("248");
INSERT INTO rsts (rst) VALUES ("238");
INSERT INTO rsts (rst) VALUES ("228");
INSERT INTO rsts (rst) VALUES ("218");
INSERT INTO rsts (rst) VALUES ("198");
INSERT INTO rsts (rst) VALUES ("188");
INSERT INTO rsts (rst) VALUES ("178");
INSERT INTO rsts (rst) VALUES ("168");
INSERT INTO rsts (rst) VALUES ("158");
INSERT INTO rsts (rst) VALUES ("148");
INSERT INTO rsts (rst) VALUES ("138");
INSERT INTO rsts (rst) VALUES ("128");
INSERT INTO rsts (rst) VALUES ("118");



