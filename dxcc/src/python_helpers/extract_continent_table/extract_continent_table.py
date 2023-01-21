#!/usr/bin/env python3

try:
    src = open('./../../src_rawdata/continents_sorted.txt', 'rt')
    dest = open('continents_tableready.txt', 'wt')

    for line in src:
        linesplit = line.split(';')
        continents = linesplit[0]
        dxccNumber = linesplit[1]

        continents_lst = continents.split(',')
        for entity in continents_lst:
            print(entity,dxccNumber)

except BaseException as err:
    print('Fehler:', err)

finally:
    src.close()
    dest.close()
