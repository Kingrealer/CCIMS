#ifndef CCMIS_H
#define CCMIS_H

#include "information.h"
#include "money.h"
#include "shop.h"
#include "user.h"

class CCMIS
{
private:
    Information*    inf;//信息表头结点
    Money*  mon;        //余额表头结点
    Shop*   sho;        //商店表头结点
    User*   use;        //用户表头结点

public:
    CCMIS() {}
    ~CCMIS() {}

    void ReadInf(string filename);          //读入整个信息表文件
    void WriteInf(string filename);         //写出整个信息表文件
    void ClearInf();                        //清空整个信息表
    void AddInf(Information* tempinf);      //添加单个信息表
    void DeleteInf(Information* tempinf);   //删除单个信息表
    void ChangeInf(Information* beforeinf, Information* afterinf);//改变单个信息表

    void ReadMoney(string filename);    //读入整个信息表文件
    void ReadShop(string filename);     //读入整个余额表文件
    void ReadUser(string filename);     //读入整个用户表文件

    void SearchNumber(int id);      //根据卡号输出信息
    void SearchSubsidy(int id);     //根据补贴输出信息
    void SearchTime(int startdate, int startime,
                    int finishdate, int finishtime);  //根据时间输出信息
};

#endif // CCMIS_H
