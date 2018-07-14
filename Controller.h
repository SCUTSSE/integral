//大致的框架。。
//start函数是程序的主消息循环，这个函数接受用户的输入并且调用其他函数来得到结果
//DealCommand函数处理用户输入的字符串，判断用户输入的模式并且提取出其中有用的字符串，当用户输入的模式
//有错误，即不匹配任何一种模式时，告诉用户输入有误
//还需要一些函数来处理用户键盘事件，比如用户按上下键时自动填充历史命令，像linux控制台那样

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "integral.h"
#include "doubleLink.h"

class Controller
{
private:
    string commandStr;
    doubleLink commandList;
public:
	void start();
	void DealCommand();
	void inputCommand();
	int GetCursorY();
	int GetCursorX();
	void SetCursorPosition(int x,int y);
};

#endif
