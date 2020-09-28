#include "forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
    currentPressure = 29.92;

    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(350, 100, 220, 220);
    this->setWindowTitle("Прогноз");


    fore = new QLabel(this);
    fore->setText("Прогноз:");
    fore->setGeometry(10,140, 190, 30);
    fore->setParent(this);
    foreLCD = new QLCDNumber(this);
    foreLCD->setGeometry(100, 110, 40, 30);
    foreLCD->setPalette(Qt::green);
    foreLCD->setParent(this);


    this->show();
}

void ForecastDisplay::update(float t, float h, float p) {
    lastPressure = currentPressure;
    currentPressure = p;
    this->display();
}

void ForecastDisplay::display() {
    cout << "Forecast: ";
    if (currentPressure > lastPressure) {
        cout << "Improving weather on the way!" << endl;
    }
    else if (currentPressure == lastPressure) {
        cout << "More of the same" << endl;
    }
    else if (currentPressure < lastPressure) {
        cout << "Watch out for cooler, rainy weather" << endl;
    }




}
