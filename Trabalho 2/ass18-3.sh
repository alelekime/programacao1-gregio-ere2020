who | cut -d ' ' -f 1
top -b -n 1 | grep -v root| sed -n '8p'| cut -d ' ' -f 3
ps -ef | grep -v root| wc -l
ssh cpu1 who| cut -d ' ' -f 1;top -b -n 1 | grep -v root| sed -n '8p'| cut -d ' ' -f 3;ps -ef | grep -v root| wc -l; ssh cpu2 who| cut -d ' ' -f 1;top -b -n 1 | grep -v root| sed -n '8p'| cut -d ' ' -f 3;ps -ef | grep -v root| wc -l;ssh orval who| cut -d ' ' -f 1;top -b -n 1 | grep -v root| sed -n '8p'| cut -d ' ' -f 3;ps -ef | grep -v root| wc -l;
quota -s
du -sm * .??* | sort -rn |head -3 | cut -f2
du -sm * .??*/* | sort -rn |head -1 | cut -f2
