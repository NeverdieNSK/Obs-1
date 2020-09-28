#include "currentconditionsdisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject *weatherData) {
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(100, 100, 220, 220);
    this->setWindowTitle("Текущие значения");

    temp = new QLabel(this);
    temp->setText("Температура:");
    temp->setGeometry(10,10, 90, 30);
    temp->setParent(this);
    tempLCD = new QLCDNumber(this);
    tempLCD->setGeometry(100, 10, 40, 30);
    tempLCD->setPalette(Qt::green);
    tempLCD->setParent(this);

    hum = new QLabel(this);
    hum->setText("Влажность:");
    hum->setGeometry(10,60, 190, 30);
    hum->setParent(this);
    humLCD = new QLCDNumber(this);
    humLCD->setGeometry(100, 60, 40, 30);
    humLCD->setPalette(Qt::green);
    humLCD->setParent(this);

    press = new QLabel(this);
    press->setText("Давление:");
    press->setGeometry(10,110, 190, 30);
    press->setParent(this);
    pressLCD = new QLCDNumber(this);
    pressLCD->setGeometry(100, 110, 40, 30);
    pressLCD->setPalette(Qt::green);
    pressLCD->setParent(this);


    this->show();
}

void CurrentConditionsDisplay::update(float t, float h, float p) {
    this->temperature = t;
    this->humidity = h;
    this->pressure = p;
    this->display();
}

void CurrentConditionsDisplay::display() {
    tempLCD->display(QString::number(temperature));
    humLCD->display(QString::number(humidity));
    pressLCD->display(QString::number(pressure));
}


