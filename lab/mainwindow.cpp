#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"log_list.h"
#include<QStringList>
#include<QProcess>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("日志管理及其关联分析系统");
    move(0,0);
    resize(650,500);
    QString host_name;
    //char* str=add_log();
    //host_name=QString(str);
    //ui->label1->setText(host_name);
    log_info();
    //init_statusbar();
   // QTimer *timer=new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(cur_time_show));
}

void MainWindow::log_info()
{
    int num;
    QStringList headers;
   QTableWidgetItem *level_item;
   QTableWidgetItem *time_item;
   QTableWidgetItem *id_item;
   QTableWidgetItem *subj_item;
   QTableWidgetItem *obj_item;
   num=3;
   ui->tableWidget->setColumnCount(5);
   ui->tableWidget->setRowCount(num);
   headers<<"级别"<<"时间"<<"ID"<<"主体"<<"客体";
   ui->tableWidget->setHorizontalHeaderLabels(headers);


}
MainWindow::~MainWindow()
{
    delete ui;
}
