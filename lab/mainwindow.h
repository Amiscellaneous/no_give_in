#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLabel>
#include<QPushButton>b
#include <QMainWindow>
class   qtab_widget;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private:
    QPushButton *shut_button;
    QLabel *cur_time_label;
    QTabWidget *tab_widget;
    QList<float> ylist;
    QList<float> ylist_1;
    void init_statusbar();
    void load_log_show();
    void add_log_show();
    void delete_log_show();
    void search_log_show();
    void cur_time_show();
    void log_info();
    void log_analyze();
};

#endif // MAINWINDOW_H
