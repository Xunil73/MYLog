

CREATE TABLE continents (
    continent_name VARCHAR(2),
    dxcc_ref_id INTEGER,
    continent_id INTEGER,
    PRIMARY KEY(continent_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);  

CREATE TABLE countries (
    dxcc_name VARCHAR(35),
    dxcc_ref_id INTEGER,
    PRIMARY KEY(dxcc_ref_id)
);

CREATE TABLE cq_zones (
    cq_zone INTEGER,
    dxcc_ref_id INTEGER,
    cq_id INTEGER,
    PRIMARY KEY(cq_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);

CREATE TABLE itu_zones (
    itu_zone INTEGER,
    dxcc_ref_id INTEGER,
    itu_id INTEGER,
    PRIMARY KEY(itu_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);

CREATE TABLE prefixes (
    prefix VARCHAR(5),
    suffix VARCHAR(5),
    dxcc_ref_id INTEGER,
    prefix_id INTEGER
    PRIMARY KEY(prefix_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);

.mode csv
.import ./../src_rawdata/tablereadys/countries_tableready.txt countries
.import ./../src_rawdata/tablereadys/continents_tableready.txt continents
.import ./../src_rawdata/tablereadys/cq_tableready.txt cq_zones
.import ./../src_rawdata/tablereadys/itu_tableready.txt itu_zones
.import ./../src_rawdata/tablereadys/prefix_tableready.txt prefixes


