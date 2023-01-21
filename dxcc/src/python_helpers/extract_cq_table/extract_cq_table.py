#!/usr/bin/env python3


try:
    src = open('./../../src_rawdata/cq_sorted.txt', 'rt')
    dest = open('cq_tableready.txt', 'wt')

    id = 1
    index = 0
    for line in src:
        linesplit = line.split(';')
        ituZones = linesplit[0].split(',')
        index = int(linesplit[1])

        for element in ituZones:
            zoneMinMax = element.split('-')
            
            result = [ int(erg) for erg in zoneMinMax ]
            common_result = [ i for i in range(min(result), max(result) + 1) ]
            for a in common_result:
                # print(a, ',', index, ',', id)
                output = str(a) + ',' + str(index) + ',' + str(id) + '\n'
                dest.write(output)
                id += 1



except BaseException as err:
    print('Fehler:', err)
 
    
finally: 
    src.close()
    dest.close()
