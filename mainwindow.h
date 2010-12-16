#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class Polynom;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateResult(int n);

private:
    Ui::MainWindow *ui;
    int maxN;
    Polynom *res;
};

#endif // MAINWINDOW_H
