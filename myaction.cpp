#include "myaction.h"

myaction::myaction(QObject *parent):
    QWidgetAction(parent)
{
    lineedit = new QLineEdit;
    connect(lineedit,&QLineEdit::returnPressed,this,&myaction::send_text);
}

//这个类是一个qaction的子类，它是用于作action的。当这个类添加到一个widget上时，这个函数就会被调用。如果没有定制的widget，那么返回0.
//此处的parent就是调用addAction的widget或者QMenu.
QWidget *myaction::createWidget(QWidget *parent)
{
    if(parent->inherits("QMenu")||parent->inherits("QToolBar"))
    {
        qDebug()<<parent;
        QSplitter *splitter = new QSplitter(parent);
        QLabel *label = new QLabel;
        label->setText("插入文本：");
        splitter->addWidget(label);
        splitter->addWidget(lineedit);
        return splitter;
    }
    return 0;
}

void myaction::send_text()
{
    emit get_text(lineedit->text());
    lineedit->clear();
}
