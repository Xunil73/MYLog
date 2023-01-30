# the files in this folder are the basic data to create a sql table with
# below we can see the structure of the csv's and code to create all tables


==> continents_tableready.txt <==
EU,1,1
OC,2,2
AS,3,3
EU,4,4
AF,5,5
# we have 'continent_name' | 'dxcc_ref_id' (fk) | 'continent_id' (pk)
CREATE TABLE continents (
    continent_name VARCHAR(2),
    dxcc_ref_id INTEGER,
    continent_id INTEGER,
    PRIMARY KEY(continent_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);  

 
==> countries_tableready.txt <==
SMO Malta,1
Minerva Reef,2
Spratly Is,3
Monaco,4
Agalega & St Brandon,5
# we have 'dxcc_name' (pk) | 'dxcc_ref_id' (fk) 
CREATE TABLE countries (
    dxcc_name VARCHAR(35),
    dxcc_ref_id INTEGER,
    PRIMARY KEY(dxcc_ref_id)
);


==> cq_tableready.txt <==
15,1,1
32,2,2
26,3,3
14,4,4
39,5,5
# we have 'cq_zone' | 'dxcc_ref_id' (fk) | 'cq_id' (pk)
CREATE TABLE cq_zones (
    cq_zone INTEGER,
    dxcc_ref_id INTEGER,
    cq_id INTEGER,
    PRIMARY KEY(cq_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);


==> itu_tableready.txt <==
28,1,1
62,2,2
50,3,3
27,4,4
53,5,5
# we have 'itu_zone' | 'dxcc_ref_id' (fk) | 'itu_id' (pk)
CREATE TABLE itu_zones (
    itu_zone INTEGER,
    dxcc_ref_id INTEGER,
    itu_id INTEGER,
    PRIMARY KEY(itu_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);


==> prefix_tableready.txt <==
1A,,1,1
1M,,2,2
9M0,,3,3
XV9,,3,4
1S,,3,5
# we have 'prefix' | 'suffix' | 'dxcc_ref_id' (fk) | 'prefix_id' (pk)
CREATE TABLE prefixes (
    prefix VARCHAR(5),
    suffix VARCHAR(5),
    dxcc_ref_id INTEGER,
    prefix_id INTEGER
    PRIMARY KEY(prefix_id),
    FOREIGN KEY(dxcc_ref_id)
    REFERENCES countries(dxcc_ref_id)
);
