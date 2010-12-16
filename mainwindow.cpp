#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "polynom.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // precalculation
    maxN = 30;
    res = new Polynom[maxN + 1];

    res[0].setOne(); // f0(c) = 1
    res[1].setVar(); // f1(c) = c
    for (int n = 2; n <= maxN; n ++)
        res[n] = res[n-1].mul_var()*2 - res[n-2];

    // setup user actions
    updateResult(1);
    connect(ui->input, SIGNAL(valueChanged(int)), this, SLOT(updateResult(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateResult(int n)
{
    if (n < 0)
    {
        ui->output->setPlainText(QString("N is too small (n=%1).").arg(n));
        return;
    }
    else if (n > maxN)
    {
        ui->output->setPlainText(QString("N is too large (n=%1).").arg(n));
        return;
    }

    ui->output->setPlainText(res[n].toString());
}
