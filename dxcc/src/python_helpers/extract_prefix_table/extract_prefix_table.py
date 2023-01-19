#!/usr/bin/env python3



try:
    src = open('./../../src_rawdata/prefixes_sorted.txt', 'rt')
    dest = open('prefix_tableready.txt', 'at')


    ascii_index = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    id = 1
    index = 0
    for line in src:
        
        linesplit = line.split(';') # eine Zeile wird aufgeteilt am Semikolon in (interne) dxccID und Liste mit den Prefixstrings 
        index = int(linesplit[1])
        raw_prefix_list = linesplit[0].split(',')

        for element in raw_prefix_list:                  
            suffix = '\t'
            if element.find('_') != -1 :  
                callpref = element.split('_')
                suffix = callpref[1]

            prfx_printout = []
            element_range = element.split('-') # wir werten den Bereich aus um die Prefixes zu expandieren (AA-AC -> AA, AB, AC oder SV1-SV3 -> SV1,SV2,SV3)
            if len(element_range) > 1:
                lastCharMinElement = 0
                lastCharMaxElement = 0
                temp = element_range[0][:-1]
                if str.isalpha(element_range[0][-1]):   # es sollen Buchstabenreihen expandiert werden
                    lastCharMinElement = ascii_index.find(element_range[0][-1])
                    lastCharMaxElement = ascii_index.find(element_range[1][-1])
                    asc_indexes = [ i for i in range(lastCharMinElement, lastCharMaxElement + 1) ]
                    for i in asc_indexes:
                        prfx_printout += [ temp + ascii_index[i] ]    #  von AA-AC wird A abgetrennt und durch AA, AB, AC ersetzt 
                else:       # sind Zahlen als letztes Zeichen im String werden diese expandiert
                    lastCharMinElement = int(element_range[0][-1])
                    lastCharMaxElement = int(element_range[1][-1])
                    numbers = [ i for i in range(lastCharMinElement, lastCharMaxElement + 1) ]
                    for i in numbers:
                        prfx_printout += [ temp + str(i) ]
                
            else:
                prfx_printout += element_range   # es war nichts zu expandieren, wir übernehmen einfach den String

            #printout data - erasing the '_Suffix'
            for element in prfx_printout:
                if element.find('_') != -1:    # wir müssen noch den Suffix abschneiden da dieser ja in der Variable suffix bereits enthalten ist
                    print('Prefix:', element[:-2], 'Suffix:', suffix, 'dxcc_index:', index)    
                else:
                    print('Prefix:', element, 'Suffix:', suffix, 'dxcc_index:', index)


except BaseException as err:
    print('Fehler:', err)

finally:
    src.close()
    dest.close()


