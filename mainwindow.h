#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBlock>
#include <QTextCursor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_enterButton_clicked();

    void on_addButton_clicked();

    void on_subButton_clicked();

    void on_multButton_clicked();

    void on_divButton_clicked();

    void on_clearButton_clicked();

    void on_xButton_clicked();

    void on_sevenButton_clicked();

    void on_fourButton_clicked();

    void on_oneButton_clicked();

    void on_zeroButton_clicked();

    void on_diffButton_clicked();

    void on_eightButton_clicked();

    void on_fiveButton_clicked();

    void on_twoButton_clicked();

    void on_negativeButton_clicked();

    void on_integrateButton_clicked();

    void on_nineButton_clicked();

    void on_sixButton_clicked();

    void on_threeButton_clicked();

    void parseLine();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
