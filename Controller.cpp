#include "Controller.h"

#include<iostream>
#include<string>
#include<regex>
#include<conio.h>
#include<windows.h>
#include "integral.h"
using namespace std;

void Controller::start()
{
    cout<<"Enter help for a prompt"<<endl;
    while(1)
    {
        commandStr="";
        inputCommand();
        commandList.addNode(commandStr);
        DealCommand();
    }
}

void Controller::DealCommand()
{
    if(commandStr=="help")
    {
        cout<<endl;
        cout<<"To calculate an antiderivative, the input should be like int(2.3x2.2-4.5x3.4) and the constant is omitted from the result"<<endl;
        cout<<"To calculate the integral, the input should be like int(2.3x2.2-4.5x3.4,2,3). The last two Numbers are lower bound and upper bound respectively"<<endl;
        cout<<"To calculate the derivative, the input should be like dif(2.3x2.2-4.5x3.4) and the constant is omitted in the result"<<endl;
        cout<<"The above values can be represented by fractions, decimals, and integers, such as int(2/3x4/5-2x3.3)"<<endl;
        cout<<endl;
        return;
    }
    if (regex_match(commandStr, regex("int[\(][\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?([\+\-][0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?)*[\)]")))
    {
        integral polyFun;
        smatch polyStr;
        regex_search(commandStr, polyStr, regex("[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?([\+\-][0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?)*"));
        polyFun.input(polyStr.str());
        cout<<polyFun.OriginFunction()<<endl;
        return;
    }
    if (regex_match(commandStr, regex("int[\(][\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?([\+\-][0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?)*,[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?,[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?[\)]")))
    {
        integral polyFun;
        smatch polyStr;
        regex_search(commandStr, polyStr, regex("[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?([\+\-][0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?)*,[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?,[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?"));
        polyFun.input2(polyStr.str());
        cout<<polyFun.CalcuValue()<<endl;
        return;
    }
     if (regex_match(commandStr, regex("dif[\(][\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?([\+\-][0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?)*[\)]")))
    {
        integral polyFun;
        smatch polyStr;
        regex_search(commandStr, polyStr, regex("[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?([\+\-][0-9]+(([\.]|[\/]){1}[0-9]+)?x[\-]?[0-9]+(([\.]|[\/]){1}[0-9]+)?)*"));
        polyFun.input(polyStr.str());
        cout<<polyFun.DifFunction()<<endl;
        return;
    }
    cout<<"Wrong Input!"<<endl;
}



void Controller::inputCommand()
{
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == -32)
        {
            ch = getch();
            if (ch == 72)       //按下上方向键
            {
                int tmpy = GetCursorY();
                int len = commandStr.length();
                SetCursorPosition(0, tmpy);
                while (len > 0)
                {
                    cout << " ";
                    len--;
                }
                SetCursorPosition(0, tmpy);
                commandList.lastNode();
                if(commandList.getCurrentString()!="")
                {
                    commandStr=commandList.getCurrentString();
                    cout<<commandStr;
                }
            }
            if (ch == 80)       //按下下方向键
            {
                int tmpy = GetCursorY();
                int len = commandStr.length();
                SetCursorPosition(0, tmpy);
                while (len > 0)
                {
                    cout << " ";
                    len--;
                }
                SetCursorPosition(0, tmpy);
                commandList.nextNode();
                if(commandList.getCurrentString()!="")
                {
                    commandStr=commandList.getCurrentString();
                    cout<<commandStr;
                }
            }
            if(ch==75)             //按下左方向键
            {
                int tmpx = GetCursorX(),tmpy=GetCursorY();
                if(tmpx>0)
                {
                    SetCursorPosition(tmpx-1, tmpy);
                }
            }
            if(ch==77)             //按下右方向键
            {
                int tmpx = GetCursorX(),tmpy=GetCursorY();
                if(tmpx<commandStr.length())
                {
                    SetCursorPosition(tmpx+1, tmpy);
                }
            }
        }
        else if(ch==8)
        {
            int tmpx = GetCursorX(),tmpy=GetCursorY();
			if(tmpx>0) {
				SetCursorPosition(tmpx-1, tmpy);
				cout<<" ";
				SetCursorPosition(tmpx-1, tmpy);
				commandStr=commandStr.substr(0,commandStr.length()-1);
			}
        }
        else
        {
            if (ch == '\r')
            {
                cout<<endl;
                commandList.resetCur();
                break;
            }
            cout<<ch;
            commandStr += ch;
            commandList.resetCur();
        }
    }
}

int Controller::GetCursorY()
{
    HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &pBuffer);
    return pBuffer.dwCursorPosition.Y;
}

int Controller::GetCursorX()
{
    HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &pBuffer);
    return pBuffer.dwCursorPosition.X;
}

void Controller::SetCursorPosition(int x,int y)
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
