#!/bin/bash
make && ./freqdict test_files/marktwain-german.txt | sort -nk 1 | less
