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
    qso_remarks VARCHAR(250),
    FOREIGN KEY (qso_prefix) REFERENCES prefixes (p_id),
    FOREIGN KEY (qso_call) REFERENCES calls (c_id),
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

# weiter bei INSERT-Anweisungen
