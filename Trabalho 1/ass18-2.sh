cut -d ';' -f 2,3,9  ensalamento.csv | grep 21A | sort -u | wc -l
cut -d ';' -f 2-9  ensalamento.csv | grep 21A | grep Teórica |wc -l
cut -d ';' -f 1-11  ensalamento.csv | grep 21A | grep 6ª | wc -l
cut -d ';' -f 1-11 ensalamento.csv | grep -o '[0-9][0-9][A-Z]'| sort -u 
cut -d ';' -f 1-11 ensalamento.csv | grep -o '[0-9][0-9][A-Z]'| sort -u |wc -l
cut -d ';' -f 1-11 ensalamento.csv | grep -v -e 21A -e 96A | grep 'Departamento de Informática' | grep -o '[0-9][0-9][A-Z]'| sort -u
cut -d ';' -f 1,9,10 ensalamento.csv | grep '[0-9][0-9][A-Z];Departamento'|sort -u| sort  -k3 -t ';'  > NovaPlanilha.csv





