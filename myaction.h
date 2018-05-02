#ifndef MYACTION_H
#define MYACTION_H

#include <QWidgetAction>
#include <QLineEdit>
#include <QString>
#include <QLineEdit>
#include <QSplitter>
#include <QLabel>
#include <QDebug>

class myaction : public QWidgetAction
{
    Q_OBJECT

public:
    myaction(QObject *parent = 0);

protected:
    QWidget *createWidget(QWidget *parent);

signals:
    void get_text(const QString string);

private slots:
    void send_text();

private:
    QLineEdit *lineedit;
};

#endif // MYACTION_H
