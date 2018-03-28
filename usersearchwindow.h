 #ifndef USERSEARCHWINDOW_H
#define USERSEARCHWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QTimer>

#include "ccmis.h"

namespace Ui {
class UserSearchWindow;
}

class UserSearchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserSearchWindow(CCMIS* c, QWidget *parent = 0);
    ~UserSearchWindow();

private slots:
    void showtime();
    void on_BackButton_clicked();

private:
    Ui::UserSearchWindow *ui;
    CCMIS* mCCMIS;
};

#endif // USERSEARCHWINDOW_H
