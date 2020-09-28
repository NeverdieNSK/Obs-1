#include "forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
    currentPressure = 29.92;
    //string tex = "";
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(200, 350, 280, 100);
    this->setWindowTitle("Прогноз");



    foreLabel = new QLabel(this);
    foreLabel->setText("Прогноза пока нет");
    foreLabel->setGeometry(10,10, 380, 20);
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
        foreLabel->setStyleSheet("QLabel { background-color : yellow; color : green; }");

          this->show();
    }
    else if (currentPressure == lastPressure) {
        foreLabel->setText("Погода усиливаеться");

          this->show();
    }
    else if (currentPressure < lastPressure) {
        foreLabel->setText("Остерегайтесь более прохладной дождливой погоды");
         foreLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");

          this->show();
    }




}
