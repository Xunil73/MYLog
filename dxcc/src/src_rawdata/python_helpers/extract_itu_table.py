#!/usr/bin/env python3


try:
    src = open('./../itu_sorted.txt', 'rt')
#   dest = open('itu_tableready.txt', 'at')

    id = 1
    for line in src:
        linesplit = line.split(';')
        ituZones = linesplit[0].split(',')


        for element in ituZones:
            zoneMinMax = element.split('-')
            
            print(zoneMinMax)

###
# die Zonen liegen als Listen von Zeichenketten vor.
# das Schema ['01','03'] wird noch nicht in [1,2,3]
# aufgeloest, das muss noch programmiert werden.
# die Variable id zaehlt noch nicht hoch
###            

    src.close()

except BaseException as err:
    print('Fehler:', err)
 
    
