#!/usr/bin/env python3



try:
    src = open('./../../src_rawdata/prefixes_sorted.txt', 'rt')
    dest = open('prefix_tableready.txt', 'at')


    ascii_index = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    id = 1
    index = 0
    for line in src:

        linesplit = line.split(';') # eine Zeile wird aufgeteilt am Semikolon in (interne) IndexID und Liste mit den Prefixstrings 
        index = int(linesplit[1])
        raw_prefix_list = linesplit[0].split(',')

        for element in raw_prefix_list:  # jedes Element des Prefixstrings wird auf Vorhandensein eines '_' untersucht, bei fehlen 
            prefix = ''                  # bleibt suffix leer
            suffix = ''
            if element.find('_') != -1 :  
                callpref = element.split('_')
                suffix = callpref[1]

            # Prefixstring muss getestet werden auf einen Bereich der dann noch expandiert werden muss (AA-AC -> AA, AB, AC)
except BaseException as err:
    print('Fehler:', err)

finally:
    src.close()
    dest.close()

