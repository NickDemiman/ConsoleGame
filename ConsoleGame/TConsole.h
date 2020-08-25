#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include<windows.h>
#include<iostream>

//цвета
#define COLOR_BLACK 0           //черный
#define COLOR_BLUE 1            //синий
#define COLOR_GREEN 2           //зеленый
#define COLOR_CYAN 3            //голубой
#define COLOR_RED 4             //красный
#define COLOR_MAGENTA 5         //фиолетовый
#define COLOR_BROWN 6           //коричневый
#define COLOR_LIGHTGRAY 7       //светло-серый
#define COLOR_DARKGRAY 8        //темно-серый
#define COLOR_LIGHTBLUE 9       //светло-синий
#define COLOR_LIGHTGREEN 10     //светло-зеленый
#define COLOR_LIGHTRED 12       //светло-красный
#define COLOR_LIGHTMAGENTA 13   //светло-фиолетовый
#define COLOR_YELLOW 14         //желтый
#define COLOR_WHITE 15          //белый
/*enum Colors {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_LIGHTGRAY,
    COLOR_DARKGRAY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
};*/

//класс консоли
class TConsole
{
private:
    HANDLE InputHandle;                         //дескриптор буфера ввода
    HANDLE OutputHandle;                        //дескриптор буфера вывода
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufInfo;   //информация об экранном буфере консоли
public:
    std::ostream& Out;              //поток вывода
    std::istream& In;               //поток ввода
    TConsole();                     //конструктор
    //TConsole(TConsole&);            //конструктор копирования*

    void ClrEol();                  //функция удаления символов от курсора до конца строки
    void ClrScr();                  //функция очистки экрана
    void Delay(WORD MS);            //функция задержки выполнения
    void DelLine();                 //функция удаления строки
    void GotoXY(int X, int Y);      //функция перемещения курсора
    void InsLine();                 //функция добавления строки
    bool KeyPressed();              //функция проверки нажатия клавиши
    WCHAR ReadKey();                //функция чтения символа с клавиатуры
    void TextBackground(BYTE Color);//функция задания цвета фона
    void TextColor(BYTE Color);     //функция задания цвета текста
    int WhereX();                   //функция получения текущей координаты X курсора
    int WhereY();                   //функция получения текущей координаты Y курсора
    void Window(BYTE X, BYTE Y);    //функция задания размеров окна

};
#endif