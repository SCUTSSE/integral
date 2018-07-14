#include "integral.h"
#include "RBTree.h"

#include<string>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;

void integral::input(string polyString)
{
    int num1=0,num2length=0;//num1为整数部分，num2位小数部分，num为整个double数字
    double coefficient=0,index=0,num2=0;
    int symbol=1;
    for(int i=0; i<polyString.length(); i++)
    {
        num1=0;
        num2=0;
        coefficient=0;
        index=0;
        num2length=0;
        symbol=1;
        if(polyString[i]=='+')
        {
            symbol=1;
            i++;
        }
        else if(polyString[i]=='-')
        {
            symbol=-1;
            i++;
        }
            //计算系数
            while(polyString[i]>='0'&&polyString[i]<='9')
            {
                num1=num1*10+polyString[i]-'0';
                i++;
            }
            if(polyString[i]=='.')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                    num2length++;
                }
                coefficient=num1+num2/pow(10,num2length);
                coefficient=coefficient*symbol;
            }
            else if(polyString[i]=='/')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                }
                if(num2!=0)
                    coefficient=num1/num2;
                else
                    coefficient=num1;
                coefficient=coefficient*symbol;
            }
            else
            {
                coefficient=num1*symbol;
            }
            //计算指数

            i++;
            if(polyString[i]=='-')
            {
                symbol=-1;
                i++;
            }
            else
            {
                symbol=1;
            }
            num1=0;
            num2=0;
            num2length=0;
            while(polyString[i]>='0'&&polyString[i]<='9')
            {
                num1=num1*10+polyString[i]-'0';
                i++;
            }
            if(polyString[i]=='.')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                    num2length++;
                }
                index=num1+num2/pow(10,num2length);
                index=index*symbol;
            }
            else if(polyString[i]=='/')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                }
                if(num2!=0)
                    index=num1/num2;
                else
                    index=num1;
                index=index*symbol;
            }
            else
            {
                index=num1*symbol;
            }
            i--;
            //向红黑树中插入一个项
            RBTNode* term=termdata.search(index);
            if(term==NULL)
            {
                termdata.insert(index,coefficient);
            }
            else
            {
                termdata.setNodeCoeff(index,term->getCoefficient()+coefficient);
            }
    }
}

void integral::input2(string polyString)
{
    int num1=0,num2length=0;//num1为整数部分，num2位小数部分，num为整个double数字
    double coefficient=0,index=0,num2=0;
    int symbol=1;
    int i;
    for(i=0; polyString[i]!=','; i++)
    {
        num1=0;
        num2=0;
        coefficient=0;
        index=0;
        num2length=0;
        symbol=1;
        if(polyString[i]=='+')
        {
            symbol=1;
            i++;
        }
        else if(polyString[i]=='-')
        {
            symbol=-1;
            i++;
        }
            //计算系数
            while(polyString[i]>='0'&&polyString[i]<='9')
            {
                num1=num1*10+polyString[i]-'0';
                i++;
            }
            if(polyString[i]=='.')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                    num2length++;
                }
                coefficient=num1+num2/pow(10,num2length);
                coefficient=coefficient*symbol;
            }
            else if(polyString[i]=='/')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                }
                if(num2!=0)
                    coefficient=num1/num2;
                else
                    coefficient=num1;
                coefficient=coefficient*symbol;
            }
            else
            {
                coefficient=num1*symbol;
            }
            //计算指数
            i++;
            if(polyString[i]=='-')
            {
                symbol=-1;
                i++;
            }
            else
            {
                symbol=1;
            }
            num1=0;
            num2=0;
            num2length=0;
            while(polyString[i]>='0'&&polyString[i]<='9')
            {
                num1=num1*10+polyString[i]-'0';
                i++;
            }
            if(polyString[i]=='.')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                    num2length++;
                }
                index=num1+num2/pow(10,num2length);
                index=index*symbol;
            }
            else if(polyString[i]=='/')
            {
                i++;
                while(polyString[i]>='0'&&polyString[i]<='9')
                {
                    num2=num2*10+polyString[i]-'0';
                    i++;
                }
                if(num2!=0)
                    index=num1/num2;
                else
                    index=num1;
                index=index*symbol;
            }
            else
            {
                index=num1*symbol;
            }
            i--;
            //向红黑树中插入一个项
            RBTNode* term=termdata.search(index);
            if(term==NULL)
            {
                termdata.insert(index,coefficient);
            }
            else
            {
                termdata.setNodeCoeff(index,term->getCoefficient()+coefficient);
            }
    }

    i++;
    num1=0;
    num2=0;
    num2length=0;
    symbol=1;
    if(polyString[i]=='+')
    {
        symbol=1;
        i++;
    }
    else if(polyString[i]=='-')
    {
        symbol=-1;
        i++;
    }
    while(polyString[i]>='0'&&polyString[i]<='9')
    {
        num1=num1*10+polyString[i]-'0';
        i++;
    }
    if(polyString[i]=='.')
    {
        i++;
        while(polyString[i]>='0'&&polyString[i]<='9')
        {
            num2=num2*10+polyString[i]-'0';
            i++;
            num2length++;
        }
        lower=num1+num2/pow(10,num2length);
        lower=lower*symbol;
    }
    else if(polyString[i]=='/')
    {
        i++;
            while(polyString[i]>='0'&&polyString[i]<='9')
            {
                num2=num2*10+polyString[i]-'0';
                i++;
            }
        if(num2!=0)
            lower=num1/num2;
        else
            lower=num1;
        lower=lower*symbol;
    }
    else
    {
        lower=num1*symbol;
    }

    i++;
    num1=0;
    num2=0;
    num2length=0;
    symbol=1;
    if(polyString[i]=='+')
    {
        symbol=1;
        i++;
    }
    else if(polyString[i]=='-')
    {
        symbol=-1;
        i++;
    }
    while(polyString[i]>='0'&&polyString[i]<='9')
    {
        num1=num1*10+polyString[i]-'0';
        i++;
    }
    if(polyString[i]=='.')
    {
        i++;
        while(polyString[i]>='0'&&polyString[i]<='9')
        {
            num2=num2*10+polyString[i]-'0';
            i++;
            num2length++;
        }
        upper=num1+num2/pow(10,num2length);
        upper=upper*symbol;
    }
    else if(polyString[i]=='/')
    {
        i++;
            while(polyString[i]>='0'&&polyString[i]<='9')
            {
                num2=num2*10+polyString[i]-'0';
                i++;
            }
        if(num2!=0)
            upper=num1/num2;
        else
            upper=num1;
        upper=upper*symbol;
    }
    else
    {
        upper=num1*symbol;
    }
}



string integral::OriginFunction()
{
    stack<double> termlist=termdata.inOrder();
    double index,coefficient;
    stringstream resultStr;
    while(!termlist.empty())
    {
        index=termlist.top();
        termlist.pop();
        coefficient=termlist.top();
        termlist.pop();
        index++;
        coefficient=coefficient*(1/index);
        if(coefficient<0)
        {
            resultStr<<coefficient<<"x"<<index;
        }
        else
        {
            if(resultStr.str()!="")
                resultStr<<"+"<<coefficient<<"x"<<index;
            else
            {
                resultStr<<coefficient<<"x"<<index;
            }
        }
    }
    return resultStr.str();
}

double integral::CalcuValue()
{
    stack<double> termlist=termdata.inOrder();
    double index,coefficient,upperNum=0,lowerNum=0;
    while(!termlist.empty())
    {
        index=termlist.top();
        termlist.pop();
        coefficient=termlist.top();
        termlist.pop();
        index++;
        coefficient=coefficient*(1/index);
        upperNum+=coefficient*pow(upper,index);
        lowerNum+=coefficient*pow(lower,index);
    }
    return upperNum-lowerNum;
}
string integral::DifFunction()
{
    stack<double> termlist=termdata.inOrder();
    double index,coefficient;
    stringstream resultStr;
    while(!termlist.empty())
    {
        index=termlist.top();
        termlist.pop();
        coefficient=termlist.top();
        termlist.pop();
        coefficient=coefficient*index;
        index--;
        if(index==-1)
        {
            if(resultStr.str()!="")
                resultStr<<"+"<<"0";
            else
                resultStr<<"0";
        }
        else if(coefficient<0)
        {
            resultStr<<coefficient<<"x"<<index;
        }
        else
        {
            if(resultStr.str()!="")
                resultStr<<"+"<<coefficient<<"x"<<index;
            else
            {
                resultStr<<coefficient<<"x"<<index;
            }
        }
    }
    return resultStr.str();
}
