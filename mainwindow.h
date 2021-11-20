#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double count_first;
    double count_second;
    double count_procent;
    bool procent = false;
    int multi_count;

    bool quals;

private slots:

    void digits_numbers();

    void on_pB_plmin_clicked();

    void on_pB_division_clicked();

    void on_pB_multi_clicked();

    void on_pB_minus_clicked();

    void on_pB_plus_clicked();

    void on_pB_equals_clicked();

    void on_pB_procent_clicked();




    void on_pB_clear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
