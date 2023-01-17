#!usr/bin/env python3



try:
    src = open('./../../src_rawdata/prefix_sorted.txt', 'rt')
    dest = open('./prefix_tableready.txt', 'wt')


ascii_index = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


except BaseException as err:
    print('Fehler:', err)

finally:
    src.close()
    dest.close()

