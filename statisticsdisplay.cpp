#include "statisticsdisplay.h"

StatisticsDisplay::StatisticsDisplay(Subject *weatherData) {
    maxTemp = 0.0;
    minTemp = 200.0;
    tempSum = 0.0;
    numReadings = 0;
    tempAvg = 0;

    this->weatherData = weatherData;
    weatherData->registerObserver(this);
    this->setGeometry(600, 100, 220, 220);
    this->setWindowTitle("Статистика");

    statmax = new QLabel(this);
    statmax->setText("Максимальная температура:");
    statmax->setGeometry(10,10, 90, 30);
    statmax->setParent(this);
    statmaxLCD = new QLCDNumber(this);
    statmaxLCD->setGeometry(160, 10, 40, 30);
    statmaxLCD->setPalette(Qt::green);
    statmaxLCD->setParent(this);

    statmin = new QLabel(this);
    statmin->setText("Минимальная температура:");
    statmin->setGeometry(10,60, 190, 30);
    statmin->setParent(this);
    statminLCD = new QLCDNumber(this);
    statminLCD->setGeometry(160, 60, 40, 30);
    statminLCD->setPalette(Qt::green);
    statminLCD->setParent(this);


        statavg = new QLabel(this);
        statavg->setText("Средняя температура:");
        statavg->setGeometry(10,110, 190, 30);
        statavg->setParent(this);
        statavgLCD = new QLCDNumber(this);
        statavgLCD->setGeometry(160, 110, 80, 30);
        statavgLCD->setPalette(Qt::green);
        statavgLCD->setParent(this);
    /*
    press = new QLabel(this);
    press->setText("Давление:");
    press->setGeometry(10,110, 190, 30);
    press->setParent(this);
    pressLCD = new QLCDNumber(this);
    pressLCD->setGeometry(100, 110, 40, 30);
    pressLCD->setPalette(Qt::green);
    pressLCD->setParent(this);
*/


    this->show();
}

void StatisticsDisplay::update(float t, float h, float p) {
    tempSum += t;
    numReadings++;
    tempAvg = tempSum/numReadings;
    if (t > maxTemp) {
        maxTemp = t;
    }

    if (t < minTemp) {
        minTemp = t;
    }
    this->display();
}

void StatisticsDisplay::display() {
    cout << "Avg/Max/Min temperature = " << tempSum / numReadings << " / "
         << maxTemp << " / " << minTemp << endl;
    //statavgLCD->display(QString::number(tempAvg));
    statmaxLCD->display(QString::number(maxTemp));
    statminLCD->display(QString::number( minTemp));
    statavgLCD->display(QString::number( tempAvg));
}

