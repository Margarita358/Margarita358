#!/bin/bash

# 1) Перевірка на наявність хоча б одного параметру
if [ $# = 0 ]
then
    echo "для команди треба вказати параметр"
    exit 1
fi

# 2) Перший параметр командного рядка
param=$1

# 3) Другий параметр командного рядка (info)
if [[ $param = 'Active' && $2 = 'info' ]]
then
    echo "Опис призначення парамутру"
fi

# 4) Вибір файлу Procfs для параметру (Active стосується CPU або пам'яті)
param_string=$(grep "$param" /proc/meminfo)

# 5) Шукаємо параметр
if [[ $? != 0 ]]
then
    echo "параметр не знайдено"
    exit 1
fi

arg_value=$(echo "$param_string" | awk -F":" '{print $2}')

# 6) Виводимо значення параметру
echo "$arg_value"

exit 0
