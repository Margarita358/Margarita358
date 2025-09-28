#!/bin/bash

# Кількість груп: 30 + номер варіанту (7) = 37
object_counter=37

# Файл зі списком команд
alias_file="groups_aliases.sh"
> "$alias_file"

# Цикл генерації
for ((i=1; i<=object_counter; i++))
do
    group_name="group$RANDOM"

    # Перевірка, чи вже існує у файлі
    if grep -q "$group_name" "$alias_file"; then
        echo "Псевдонім $group_name вже існує!"
    else
        echo "groupadd $group_name" >> "$alias_file"
        echo "Псевдонім $group_name додано."
    fi
done

chmod +x "$alias_file"
exit 0
