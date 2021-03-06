#include "administratorleadwindow.h"
#include "ui_administratorleadwindow.h"

AdministratorLeadWindow::AdministratorLeadWindow(CCIMS *c, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorLeadWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);

    mCCIMS = c;

    //时间处理
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_dispose()));
    timer->start(500);

    //基本信息展示
    ui->UserName->setText(mCCIMS->GetCurrentUserName());

    //图片导入
    QIcon icon;
    std::string str = mCCIMS->FilenameCorrect
            (mCCIMS->BACKBUTTON_PICTURE_NAME).toStdString();
    const char* address = str.c_str();  //转地址QString到char*
    icon.addFile(tr(address));
    ui->BackButton->setIcon(icon);
}

AdministratorLeadWindow::~AdministratorLeadWindow()
{
    delete ui;
}

void AdministratorLeadWindow::time_dispose()
{
    ui->Time->display(AboutUI::ShowDateTime());
}

void AdministratorLeadWindow::on_BackButton_clicked()
{
    parentWidget()->setGeometry(this->x(),this->y(),this->width(),this->height());
    parentWidget()->show();
    this->close();
}

void AdministratorLeadWindow::on_WorkButton_clicked()
{
    QString txt = ui->AddressLine->text();
    QMessageBox* msg = new QMessageBox(this);
    unsigned int number = mCCIMS->ImportInf(txt.toStdString());
    if (number > 0){
     msg->setText(tr("导入成功！导入") +
                     QString::number(number,10).toStdString().data()
                     + tr("条信息"));
    }else{
     msg->setText(tr("导入失败！"));
    }
    msg->show();
}
