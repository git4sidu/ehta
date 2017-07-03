#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "udpsend.h"

MainWindow::U u;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 29999);
    connect(socket, SIGNAL(readyRead()), this, SLOT (MyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MyRead()
    {
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        socket->readDatagram(buffer.data(),buffer.size(), &sender, &senderPort);

        memcpy(u.str, buffer,64);
        qDebug()<<"itime: "<<itime++;
        qDebug()<< "time: "<<(u.pack.time)/1000;
        qDebug()<<"angvel["<<u.pack.angvel[0]<<","<<u.pack.angvel[1]<<","<<u.pack.angvel[2]<<"]";
        qDebug()<<"header: "<<u.pack.header*180/3.141592+180;
        qDebug()<<"pitch: "<<u.pack.pitch;
        qDebug()<<"roll: "<<u.pack.roll;
        qDebug()<<"accel["<<u.pack.accel[0]<<","<<u.pack.accel[1]<<","<<u.pack.accel[2]<<"]";
        qDebug()<<"vel["<<u.pack.vel[0]<<";"<<u.pack.vel[1]<<";"<<u.pack.vel[2]<<"]";
        qDebug()<<"pos["<<u.pack.pos[0]<<";"<<u.pack.pos[1]<<";"<<u.pack.pos[2]<<"]\n";
        //HelloUDP();

        /*if (u.pack.roll>MaxRoll)
            MaxRoll=u.pack.roll;
        if(u.pack.roll<MinRoll)
            MinRoll=u.pack.roll;
        if (u.pack.pitch>MaxPitch)
            MaxPitch=u.pack.pitch;
        if(u.pack.pitch<MinPitch)
            MinPitch=u.pack.pitch;
       */
        MaxRoll=u.pack.roll*490+50;
        MaxPitch=u.pack.pitch*490+50;

        ui->Slider_x_rot->setValue(MaxPitch);
        ui->Slider_y_rot->setValue(MaxRoll);

        qDebug()<<"MaxRoll: "<<MaxRoll;
        //qDebug()<<"MinRoll: "<<MinRoll;
        qDebug()<<"MaxPitch: "<<MaxPitch;
        //qDebug()<<"MinPitch: "<<MinPitch;
        //qDebug()<<sizeof(u);
        //qDebug()<<"strlen(buffer): "<<strlen(buffer.toHex());
}

void MainWindow::JustSend()
{
    QByteArray Data;
    Data.append(MainWindow::ui->textEdit->toPlainText());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::JustSend();

}

void MainWindow::on_Slider_x_valueChanged(int value)
{
    QByteArray Data;
    Data.append("A");
    Data.append(ui->Slider_x->value());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}

void MainWindow::on_Slider_y_valueChanged(int value)
{
    QByteArray Data;
    Data.append("B");
    Data.append(ui->Slider_y->value());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}

void MainWindow::on_Slider_z_valueChanged(int value)
{
    QByteArray Data;
    Data.append("C");
    Data.append(ui->Slider_z->value());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}

void MainWindow::on_Slider_x_rot_valueChanged(int value)
{
    QByteArray Data;
    Data.append("D");
    Data.append(ui->Slider_x_rot->value());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}

void MainWindow::on_Slider_y_rot_valueChanged(int value)
{
    QByteArray Data;
    Data.append("E");
    Data.append(ui->Slider_y_rot->value());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}

void MainWindow::on_Slider_z_rot_valueChanged(int value)
{
    QByteArray Data;
    Data.append("F");
    Data.append(ui->Slider_z_rot->value());
    socket->writeDatagram(Data, QHostAddress(ui->textEdit_IP->toPlainText()), (ui->textEdit_Port->toPlainText()).toInt());
}
