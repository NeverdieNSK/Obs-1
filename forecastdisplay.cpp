#include "forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
    currentPressure = 29.92;
    //string tex = "";
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(350, 100, 220, 220);
    this->setWindowTitle("Прогноз");

/*

    fore = new QLabel(this);
    fore->setText("Прогноз 55:");
    fore->setGeometry(10,10, 190, 30);
    fore->setParent(this);

*/

    this->show();
}

void ForecastDisplay::update(float t, float h, float p) {
    lastPressure = currentPressure;
    currentPressure = p;
    this->display();
}

void ForecastDisplay::display() {
   // cout << "Forecast: ";
    if (currentPressure > lastPressure) {
       // cout << "Improving weather on the way!"<< endl;
        fore = new QLabel(this);
        fore->setText("Improving weather on the way!");
        fore->setGeometry(10,50, 190, 30);
        fore->setParent(this);
          this->show();
    }
    else if (currentPressure == lastPressure) {
        //cout << "More of the same" << endl;
        fore = new QLabel(this);
        fore->setText("More of the same");
        fore->setGeometry(10,50, 190, 30);
        fore->setParent(this);
          this->show();
    }
    else if (currentPressure < lastPressure) {
       // cout << "Watch out for cooler, rainy weather" << endl;
        fore = new QLabel(this);
        fore->setText("Watch out for cooler, rainy weather");
        fore->setGeometry(10,50, 190, 30);
        fore->setParent(this);
          this->show();
    }




}
