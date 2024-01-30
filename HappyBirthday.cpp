#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

void printWithTypingEffect(wstring s, int delay) {
    for (wchar_t c : s) {
        wcout << c;
        Sleep(delay);
    }
}

void playHappyBirthdayTune() {
    int notes[] = {262, 262, 294, 262, 349, 330,
                    262, 262, 294, 262, 392, 349,
                    262, 262, 523, 440, 349, 330, 294,
                    494, 494, 440, 349, 392, 349};
    int duration[] = {250, 250, 500, 500, 500, 1000,
                      250, 250, 500, 500, 500, 1000,
                      250, 250, 500, 500, 500, 500, 1000,
                      250, 250, 500, 500, 500, 1000};
    for (int i = 0; i < sizeof(notes) / sizeof(int); i++) {
        Beep(notes[i], duration[i]);
    }
}

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    srand(time(NULL));

    SET_COLOR(1);
    wcout << L"Hãy nhập tên của bạn: ";
    wstring name;
    SET_COLOR(14);
    getline(wcin, name);

    SET_COLOR(1);
    wcout << L"Xin chào "; SET_COLOR(14); wcout << name; SET_COLOR(1); wcout << L", hôm nay là sinh nhật của ai?\n";
    wcout << L"Hãy nhập tên của người mà bạn muốn chúc mừng: ";
    wstring birthdayName;
    SET_COLOR(14);
    getline(wcin, birthdayName);

    SET_COLOR(1);
    wcout << L"Bạn muốn gửi lời chúc gì đến "; SET_COLOR(14); wcout << birthdayName; SET_COLOR(1); wcout << "?\n";
    wcout << L"Hãy nhập lời chúc của bạn: ";
    SET_COLOR(5);
    wcin.ignore();
    wstring message;
    getline(wcin, message);

    system("cls");

    SET_COLOR(1);
    wcout << L"Chuẩn bị chúc mừng sinh nhật cho ";  SET_COLOR(14); wcout << birthdayName;  SET_COLOR(1); wcout << "...\n";
    Sleep(3000);
    system("cls");

    printWithTypingEffect(L"Chúc mừng sinh nhật ", 100);
    SET_COLOR(14);
    wcout << (birthdayName + L"!!!\n\n");
    SET_COLOR(1);
    printWithTypingEffect(L"Đây là lời chúc từ ", 100);  SET_COLOR(14);     
    wcout << name << L": " << endl;
    SET_COLOR(5);
    wcout << L"h" << (message + L"\n\n");
    wcout << "MUSIC!!!!" << endl;

    playHappyBirthdayTune();

    printWithTypingEffect(L"\nHappy Birthday Mặt trời xinh đẹp!!!\n", 100);
    SET_COLOR(9);
    printWithTypingEffect(L"\n\nCảm ơn cậu đã dành thời gian để đọc những lời chúc của tớ!\n", 100);
    printWithTypingEffect(L"Chúc ", 100); SET_COLOR(14); printWithTypingEffect(birthdayName, 100); SET_COLOR(9); 
    printWithTypingEffect(L" có một ngày sinh nhật thật zui zẻe!!!\n", 100);

    getch();
    return 0;
}
