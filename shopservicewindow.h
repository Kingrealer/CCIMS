#ifndef SHOPSERVICEWINDOW_H
#define SHOPSERVICEWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QTimer>

#include "shopsuccesswindow.h"
#include "shopfailwindow.h"

namespace Ui {
class ShopServiceWindow;
}

class ShopServiceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShopServiceWindow(QWidget *parent = 0);
    ~ShopServiceWindow();

public slots:
    void showtime();
    void ShowNameSlot(QString);

private slots:
    //重新显示主界面：X，Y，宽，长
    void reshow(int,int,int,int);
    void on_BackButton_clicked();

signals:
    //返回主界面：X，Y，宽，长
    void BackMainWindow(int,int,int,int);
    void ShowNameSignal(QString);

private:
    Ui::ShopServiceWindow *ui;
    ShopSuccessWindow *mSSW;
    ShopFailWindow *mSFW;
};

#endif // SHOPSERVICEWINDOW_H