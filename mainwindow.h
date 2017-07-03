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



         quint32 itime=0;
         struct outsim_pack{
                 quint32 time;
                 float angvel[3];
                 float header;
                 float pitch;
                 float roll;
                 float accel[3];
                 float vel[3];
                 qint32 pos[3];
             };

         union U{
             char str[64];
             struct outsim_pack pack;
         };

float MaxRoll=0, MinRoll=0, MinPitch=0, MaxPitch=0;

public slots:
    void MyRead();

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
