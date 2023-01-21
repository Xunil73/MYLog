# extract_cq_table.py is a script that creates a 
# comma separated file that can be used to fill a 
# sql-table with columns:
# |cqZoneNumber|dxccID|uniqueID|
# where dxccID is a own created id matching the dxcc entities in the 
# list countries_sorted.txt
# uniqueID is the increment ID to point to an unique row in the list

# the script catches the source file from MYLog/dxcc/src/src_rawdata/cq_sorted>
# and outputs the comma separated file in the same folder as the script is
# (this folder)

