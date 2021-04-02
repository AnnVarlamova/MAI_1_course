#!/usr/bin/python3.9   #выбран интерпретатор

import os   #подключен модуль

name = input("Enter name of creating file: ")  #пользовательский ввод, переменная будет хранить префикс файла,
#в который будет записываться результат программы
if name == "?":  #подсказка для пользователя
    name = input("Press any letters: ")

suffix = input("Enter suffix for searching: ") #пользовательский ввод, переменная будет хранить суффикс файлов,
                                                #которые захочет проверить пользователь
if suffix == "?":   #подсказка для пользователя
    suffix = input("Press point and then file extention: ")

size = int(input("Enter max size of creating file in bytes: "))
                    #пользовательский ввод, переменная будет хранить размер файла,
                    # в который будет записываться результат программы
for file in os.listdir(path = "."): #просмотр файлов в текущей папке
    if file.endswith(suffix) and os.access(file, os.X_OK): #проверка на суффикс и на выполнимость(os.X_OK)
                        #os.access для проверки доступа, но предполагаем, что имеем доступ к файлам
        crfile = open(name + '1.txt', 'a') #создаём и открываем файл в режиме дозаписи
        crfile.write(os.path.basename(file) + ' ') #записываем в файл имя файла
        crfile.write(str(os.path.getsize(file)) + ' bytes\n') #записываем в файл размер файла в байтах
        crfile.close() #закрываем файл, чтобы открыть в следующем цикле
print('\nYour file\n') #для красоты
os.truncate(name + '1.txt', size) #обрезка файла до заданного размера
crfile = open(name + '1.txt', 'r') #открытие для чтения
lines = crfile.readlines() #считывание построчно
crfile.close() #закрыли файл, чтобы открыть в другом режиме доступа
ourf = open(name + '.txt', 'w') #открытие в режиме записи
for line in lines:  #цикл строк файла
    if "bytes" in line: #записываем в конечный файл только полные строки
        ourf.write(line)
ourf.close()
ourf = open(name + '.txt', 'r') #открытие в режиме чтения
spisok = ourf.read() #запись файла  в переменную
print(spisok) #вывод файла для удобства
ourf.close() #а так файл можно найти в той же директории
