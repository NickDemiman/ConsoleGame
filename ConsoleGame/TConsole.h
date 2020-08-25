#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include<windows.h>
#include<iostream>

//�����
#define COLOR_BLACK 0           //������
#define COLOR_BLUE 1            //�����
#define COLOR_GREEN 2           //�������
#define COLOR_CYAN 3            //�������
#define COLOR_RED 4             //�������
#define COLOR_MAGENTA 5         //����������
#define COLOR_BROWN 6           //����������
#define COLOR_LIGHTGRAY 7       //������-�����
#define COLOR_DARKGRAY 8        //�����-�����
#define COLOR_LIGHTBLUE 9       //������-�����
#define COLOR_LIGHTGREEN 10     //������-�������
#define COLOR_LIGHTRED 12       //������-�������
#define COLOR_LIGHTMAGENTA 13   //������-����������
#define COLOR_YELLOW 14         //������
#define COLOR_WHITE 15          //�����
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

//����� �������
class TConsole
{
private:
    HANDLE InputHandle;                         //���������� ������ �����
    HANDLE OutputHandle;                        //���������� ������ ������
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufInfo;   //���������� �� �������� ������ �������
public:
    std::ostream& Out;              //����� ������
    std::istream& In;               //����� �����
    TConsole();                     //�����������
    //TConsole(TConsole&);            //����������� �����������*

    void ClrEol();                  //������� �������� �������� �� ������� �� ����� ������
    void ClrScr();                  //������� ������� ������
    void Delay(WORD MS);            //������� �������� ����������
    void DelLine();                 //������� �������� ������
    void GotoXY(int X, int Y);      //������� ����������� �������
    void InsLine();                 //������� ���������� ������
    bool KeyPressed();              //������� �������� ������� �������
    WCHAR ReadKey();                //������� ������ ������� � ����������
    void TextBackground(BYTE Color);//������� ������� ����� ����
    void TextColor(BYTE Color);     //������� ������� ����� ������
    int WhereX();                   //������� ��������� ������� ���������� X �������
    int WhereY();                   //������� ��������� ������� ���������� Y �������
    void Window(BYTE X, BYTE Y);    //������� ������� �������� ����

};
#endif