    Обработка исключительных ситуаций

Условие:
    Реальизовать базовый класс исключений и иерархию произвольных классов
исключений с

file.hpp:

               Exp
                |
    -------------------------
    |           |           |
   arr      DataInput   dataOverflow 

DataInput - ошибки ввода (ввод символа вместо числа и т.д.)
dataOverflow - ошибки при переполнении данных(невозможные даты и т.д.)
Arr - ошибки при работе с массивами