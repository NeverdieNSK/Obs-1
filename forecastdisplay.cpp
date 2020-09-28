#include "forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
    currentPressure = 29.92;
    //string tex = "";
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(350, 100, 220, 220);
    this->setWindowTitle("Прогноз");



    foreLabel = new QLabel(this);
    foreLabel->setText("Прогноза пока нет");
    foreLabel->setGeometry(10,10, 190, 30);
    foreLabel->setParent(this);



    this->show();
}

void ForecastDisplay::update(float t, float h, float p) {
    lastPressure = currentPressure;
    currentPressure = p;
    this->display();

}

void ForecastDisplay::display() {

    if (currentPressure > lastPressure) {
        foreLabel->setText("Ожидаем улучшение погоды");
        foreLabel->setGeometry(10,50, 190, 30);
        foreLabel->setParent(this);
          this->show();
    }
    else if (currentPressure == lastPressure) {
        foreLabel->setText("Погода усиливаеться");
        foreLabel->setGeometry(10,50, 190, 30);
        foreLabel->setParent(this);
          this->show();
    }
    else if (currentPressure < lastPressure) {
        foreLabel->setText("Остерегайтесь более прохладной дождливой погоды");
        foreLabel->setGeometry(10,50, 190, 30);
        foreLabel->setParent(this);
          this->show();
    }




}
