#!/usr/bin/env python3

try:
    src = open('./../../src_rawdata/continents_sorted.txt', 'rt')
    dest = open('continents_tableready.txt', 'wt')

    pk_id = 1
    for line in src:
        linesplit = line.split(';')
        continents = linesplit[0]
        dxccNumber = linesplit[1][:-1]  # there is a newline we have to delete [:-1]

        continents_lst = continents.split(',')
        for entity in continents_lst:
            outputstring = entity + ',' + dxccNumber + ',' + str(pk_id) + '\n'
            print(outputstring)
            dest.write(outputstring)
            pk_id += 1

except BaseException as err:
    print('Fehler:', err)

finally:
    src.close()
    dest.close()
