#!/bin/bash

cut -d ';' -f 2,3,9  ensalamento.csv | uniq -d | grep 21A | wc -l
cut -d ';' -f 2,3,8,9  ensalamento.csv | grep 21A | grep Teórica |wc -l
cut -d ';' -f 2,3,4,5,9  ensalamento.csv | grep 21A | grep 6ª | wc -l
cut -d ';' -f 1 ensalamento.csv |sort| uniq -u
cut -d ';' -f 1 ensalamento.csv |sort| uniq -u | wc -l




