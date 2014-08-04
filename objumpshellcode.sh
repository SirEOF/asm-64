#!/bin/bash
# By Mh4
# Name:   od2sc (objdump to shellcode)
# Usage:  od2sc <object_file>

objdump -D $1 \
| awk -F'\t' '{print $2}' \
| grep -v ^$ \
| tr -d '\n' \
| sed -e 's/ \+/\\x/g' -e 's/^/"\\x/' -e 's/\\x$/\"\n/'
