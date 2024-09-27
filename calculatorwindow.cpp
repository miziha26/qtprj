#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <QDebug>
CalculatorWindow::CalculatorWindow(ToolForm*tool,QWidget *parent)
    : QMainWindow(parent),tool(tool)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../pic/calo.png"));
    this->setWindowTitle("计算器");

    //当按钮组中有按钮按下时就会发出信号，判断是哪个按键按下
    connect(ui->buttonGroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(slotButtonGroupClicked(QAbstractButton*)));
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::showWindow()
{
    //保存用户账号信息
    //隐藏切换前的界面
    if(tool->cur_widget)
    {
        tool->cur_widget->hide();
    }
    //设置当前界面为计算器界面
    tool->cur_widget = this;
    tool->setParent(this);
    //设置跳转框位置
    int x=ui->toolButton_calo->x()-273;
    int y=ui->toolButton_calo->y();

    tool->move(x,y);
    tool->hide();
    ui->toolButton_calo->setChecked(false);
    //显示计算器界面
    show();
}

void CalculatorWindow::slotButtonGroupClicked(QAbstractButton *button)
{
    QString text = button->text();
    if(text == "c")
    {
        //将输入框中的内容清空
        ui->lineEdit->clear();
        //将表达式的内容清空
        express.clear();
    }
    else if(text == "x")
    {
        //删除一位
        express.chop(1);    //从字符串末尾删除1个字符
    }
    else if(text == "=")
    {
        //计算表达式
        express = calculate();
    }
    else
    {
        //数字和运算符
        if(express.isEmpty())
        {
            if(text == "+" or text == "*" or text == "/" or text == "%")
            {
                express += "0";
            }
        }
        express += text;
    }
    ui->lineEdit->setText(express);
}




void CalculatorWindow::on_toolButton_calo_clicked(bool checked)
{
    if(checked)
    {
        tool->show();
    }
    else
    {
        tool->hide();
    }
}


void CalculatorWindow::on_lineEdit_textChanged(const QString &str)
{
    if(str.isEmpty())
    {
        //表达式为空，将结果设置为0
        ui->lineEdit->setText("0");
    }
}

QString CalculatorWindow::calculate()
{
    if(express.isEmpty())
    {
        return "0";
    }
    //将中缀表达式转换成后缀表达式
    midToPost();
    //计算后缀表达式
    return calculatePost();
}

void CalculatorWindow::midToPost()
{
    //遍历整个表达式，提取操作数和运算符
    //如果是操作数，直接入队
    //如果是运算符，入栈
    //如果栈为空，直接入栈
    //如果待入栈元素优先级比栈顶元素优先级高，入栈
    //否则(平级或低)，将栈顶元素出栈入队，直到待入栈元素优先级比栈顶元素高或者栈空，入栈
    //表达式遍历完后，将栈中的运算符依次出栈入队
    //队列中保存的表达式就是后缀表达式
    QString number;
    for(int i = 0; i < express.length(); i++)
    {
        //操作数提取出来，是由一个或多个0~9的字符组成
        if(express.at(i) >= '0' and express.at(i) <= '9')
        {
            //将多个数字字符拼接成一个数字字符串
            number += express.at(i);
        }
        else if(express[i] == '+' or express[i] == '-' or express[i] == '*' or express[i] == '/' or express[i] == '%')
        {
            //是一个运算符
            //将操作数入队
            queue.enqueue(number);
            //清空数字字符串，方便提取下一个数字
            number.clear();
            //运算符入栈
            operatorPushStack(express.at(i));
        }
    }
    //手动入队最后一个操作数，因为它的后面没有运算符了
    queue.enqueue(number);
    //将栈中的运算符依次出栈入队
    while(!stack.isEmpty())
    {
        queue.enqueue(stack.pop());
    }
    //打印后缀表达式
    qDebug() << queue;
}

void CalculatorWindow::operatorPushStack(QString op)
{
    //如果栈为空，直接入栈
    //如果待入栈元素优先级比栈顶元素优先级高，入栈
    //否则(平级或低)，将栈顶元素出栈入队，直到待入栈元素优先级比栈顶元素高或者栈空，入栈
    while(!stack.isEmpty())
    {
        if((op == "*" or op == "/" or op == "%") and (stack.top() == "+" or stack.top() == "-"))
        {
            //当待入栈的元素为*/%，并且栈顶元素为+或-的时候，才会出现待入栈的优先级比栈顶优先高的情况
            break;
        }
        else
        {
            //栈顶元素出栈，入队
            queue.enqueue(stack.pop());
        }
    }
    stack.push_back(op);
}

QString CalculatorWindow::calculatePost()
{
    //将队列中的元素依次出队
    //如果出队的元素是一个操作数，直接入栈
    //如果出队的元素是一个运算符，则出栈两个操作数
    //出栈的第一个元素作为第二个操作数
    //出栈的第二个元素作为第一个操作数
    //将出栈的两个操作数和运算符进行运算，将运算的结果入栈
    //直到队列为空，此时栈顶元素就是计算的结果！
    QString o;
    QString res;
    int a,b;
    bool ok;
    while(!queue.isEmpty())
    {
        o = queue.front();//先拿到o再出队，pop_front不会返回任何值
        queue.pop_front();
        if(o.toInt(&ok,10))
        {
            stack.push(o);
        }
        else
        {
            a = stack.pop().toInt();
            b = stack.pop().toInt();
            switch (o.at(0).toLatin1())
            {
                case '+':
                    res = QString::number(b+a);
                    stack.push(res);
                    break;
                case '-':
                    res = QString::number(b-a);
                    stack.push(res);
                    break;
                case '*':
                    res = QString::number(b*a);
                    stack.push(res);
                    break;
                case '/':
                    res = QString::number(b/a);
                    stack.push(res);
                    break;
                case '%':
                    res = QString::number(b%a);
                    stack.push(res);
                    break;
                default:
                    break;
            }
        }

    }
    return stack.top();
}
/*
toInt(&ok, 10) 是 QString 类的一个成员函数,用于将字符串转换为整数。它有以下两个参数:
&ok: 这是一个指向 bool 类型的指针。函数执行完成后,会将转换是否成功的结果存储在这个指针指向的 bool 变量中。
如果转换成功,ok 将被设置为 true,否则为 false。
10: 这是转换时使用的进制。在这里,我们使用了十进制,即基数为 10。
这个函数的返回值是转换后的整数值。如果转换失败,则返回 0。
使用这个函数的好处是,可以同时获得转换是否成功的信息。这样可以更好地处理输入错误的情况。
例如,如果输入的字符串无法转换为整数,可以给出相应的错误提示。

toLatin1() 是 QChar 类的一个成员函数,用于将 QChar 对象转换为 char 类型。
在 Qt 中,QChar 是用于表示单个字符的类型。它可以表示各种字符编码,包括 Unicode、Latin-1 等。
toLatin1() 函数将 QChar 对象转换为 Latin-1 编码的 char 类型。Latin-1 是一种 8 位字符编码,
可以表示 0-255 范围内的字符。这个函数的主要用途是:
当需要将 QChar 对象传递给一些只接受 char 类型参数的函数时,可以使用 toLatin1() 进行转换。
在某些情况下,需要将 QChar 对象转换为 char 类型进行比较或其他操作。
需要注意的是,如果 QChar 对象表示的字符不在 Latin-1 编码范围内,toLatin1() 函数会返回一个默认值 '\0'。
因此,在使用 toLatin1() 时,需要先确保字符可以被 Latin-1 编码表示。
*/







