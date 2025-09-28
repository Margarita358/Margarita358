#!/usr/bin/awk -f
# Скрипт для обробки /etc/group (рядок 7, стовпчики 1 та 3)

BEGIN { FS=":" }
NR==7 { print $1, $3 }
