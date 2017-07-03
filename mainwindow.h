#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "udpsend.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
         void JustSend();

private slots:
    void on_pushButton_clicked();

    void on_Slider_x_valueChanged(int value);

    void on_Slider_y_valueChanged(int value);

    void on_Slider_z_valueChanged(int value);

    void on_Slider_x_rot_valueChanged(int value);

    void on_Slider_y_rot_valueChanged(int value);

    void on_Slider_z_rot_valueChanged(int value);
private:
    Ui::MainWindow *ui;
    QUdpSocket *socket;

};

#endif // MAINWINDOW_H
