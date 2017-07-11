#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <memory>
#include <QImage>
#include <QDebug>
#include <iostream>
#include "command.h"
class OpenFileCommand;

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

    void update();
    void set_img(std::shared_ptr<QImage> image);
    void set_open_file_command(std::shared_ptr<Command>);
    void test(){
        std::cout << q_image.get() << "test" << std::endl;
        qInfo() << "test";

    }

private slots:
    void on_button_open_clicked();

private:
    Ui::View *ui;
    std::shared_ptr<QImage> q_image;
    std::shared_ptr<Command> open_file_command;
};

#endif // VIEW_H
