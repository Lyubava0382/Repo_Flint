#include <iostream>
#include <locale.h>
#include <math.h>
#include <fstream>
#include<iomanip>
#include <cmath>
#include  <SFML/Graphics.hpp>

using namespace std;
double const q=-1.6, m=9.11, ke=9, kb=30;///задание констант для заряда электрона, массы электрона и коэффициентов пропорциональности для электрического и магнитного поля соответственно

class field///создание класса
{
private:
    int amount;///объявление переменной amount - количество точек
    int amount_now;///объявление переменной amount_now - количество вычисленных точек
    double amountdouble, time, step;///amountdouble - количество точек, time - время движения заряда, step - шаг
    double E_x, E_y, E_z, B_x, B_y, B_z;///объявление переменных E_x, E_y, E_z, E_xo, E_yo, E_zo, B_x, B_y, B_z отвечающих за начальное и последующие положения электрического и магнитного поля соответственно
    double V_x, V_y, V_z;///объявление переменных V_x, V_y, V_z - последующая и предыдущая координаты скорости соответственно
    double X, Y, Z;///объявление переменных X_1, Y_1, Z_1, X, Y, Z - последующее и предыдущее положение частицы соответственно, r, re, rb - расстояние от точки до электрического и магнитного поля соответственно
    double *array_x, *array_y, *array_z;
    double Fe_x, Fe_y, Fe_z, Fb_x, Fb_y, Fb_z, Fsumm_x, Fsumm_y, Fsumm_z;///объявление переменных Fe_x, Fe_y, Fe_z, Fb_x, Fb_y, Fb_z - силы, с которыми электрическое и магнитное поле соответственно действуют на электрический заряд, Fsumm_x, Fsumm_y, Fsumm_z - сумма электрической и магнитной силы
public:
    ///создание конструктора с объявлением переменных
    field(double _step, double _time) : step(_step), time(_time){
        amountdouble = ((time / step) + 1);///расчет количества точек
        amount = static_cast<int>(amountdouble);///присваивание переменной значение количества точек типа int
        cout << amount << '\n';///вывод на экран
        amount_now = 0;
        array_x = new double[amount];
        array_y = new double[amount];
        array_z = new double[amount];
    }
    void setElectricStrength(double E_x, double E_y, double E_z){
        this->E_x = E_x;
        this->E_y = E_y;
        this->E_z = E_z;
    }
    void setSpeed(double V_x, double V_y, double V_z){
        this->V_x = V_x;
        this->V_y = V_y;
        this->V_z = V_z;
    }
    void setInduction(double B_x, double B_y, double B_z){
        this->B_x = B_x;
        this->B_y = B_y;
        this->B_z = B_z;
    }
    void setCoord(double X, double Y, double Z){
        this->X = X;
        this->Y = Y;
        this->Z = Z;
    }



void print() {
using namespace sf;
int W = 500; // Ширина и высота окна
    int H = 500;
    RenderWindow windowX(VideoMode(W, H), "Graphic X / time");
    RenderWindow windowY(VideoMode(W, H), "Graphic Y / time");
    RenderWindow windowZ(VideoMode(W, H), "Graphic Z / time");
    VertexArray line(Lines, 2);
    line[0].position = Vector2f(W/10, 0);
    line[0].color = Color::Blue;
    line[1].position = Vector2f(W/10, H);
    line[1].color = Color::Magenta;
    
    VertexArray linet(Lines, 3);
    linet[0].position = Vector2f(0, H/2);
    linet[0].color = Color::Blue;
    linet[1].position = Vector2f(W, H/2);
    linet[1].color = Color::Magenta;
    
    VertexArray linesX(sf::LineStrip, amount);
    VertexArray linesY(sf::LineStrip, amount);
    VertexArray linesZ(sf::LineStrip, amount);
 
 int size_gr = 100000; //Масштаб
 double step_gr = (W-100)/amount;
    double t = 0.0;
    for (int i = 0; i < amount; i++) {
        linesX[i].position = Vector2f(int(t + W/10), H/2 - array_x[i]/size_gr);
        linesX[i].color = Color::Red;
        
        linesY[i].position = Vector2f(int(t + W/10), H/2 - array_y[i]/size_gr);
        linesY[i].color = Color::Yellow;
        
        linesZ[i].position = Vector2f(int(t + W/10), H/2 - array_z[i]/size_gr);
        linesZ[i].color = Color::Green;
        
        t += step_gr;
        
    }
 
    while (windowX.isOpen() && windowY.isOpen() && windowZ.isOpen()) {
        // Конструктор обработчика событий
        Event event;
        while (windowX.pollEvent(event)) {
            if (event.type == Event::Closed)
                windowX.close();
        }
        while (windowY.pollEvent(event)) {
            if (event.type == Event::Closed)
                windowY.close();
        }
        while (windowZ.pollEvent(event)) {
            if (event.type == Event::Closed)
                windowZ.close();
        }
        windowX.clear();
        windowY.clear();
        windowZ.clear();
        windowX.draw(line);
        windowY.draw(line);
        windowZ.draw(line);
        windowX.draw(linet);
        windowY.draw(linet);
        windowZ.draw(linet);
        windowX.draw(linesX);
        windowY.draw(linesY);
        windowZ.draw(linesZ);
        windowX.display();
        windowY.display();
        windowZ.display();
        }
       }
    
    /*void zapis(char Zapis[])///создание функции записи решений в файл
    {
        ofstream fout(Zapis, ios::app);///запись в фаил "Zapis"
        fout << X << setw(20) << Y << setw(20) << Z << '\n';///вывод в файл значений Х, Y, Z - положения частицы
        fout.close();///конец записи
    }*/

    ///создание функции для расчета траектории частицы в однородном поле
    void odnorodnoe()
    {

        for (int i = 0; i < amount; i++)///задание цикла для расчета координат частицы
        {
            ///расчет силы, с которой электрическое поле действует на электрический заряд
            Fe_x = q * E_x;
            Fe_y = q * E_y;
            Fe_z = q * E_z;

            ///расчет силы, с которой магнитное поле действует на электрический заряд
            Fb_x = q * (V_y * B_z - V_z * B_y);
            Fb_y = -q * (V_x * B_z - V_z * B_x);
            Fb_z = q * (V_x * B_y - V_y * B_x);

            ///расчет суммы сил, с которыми электрическое и магнитное поле действуют на электрический заряд
            Fsumm_x = Fe_x + Fb_x;
            Fsumm_y = Fe_y + Fb_y;
            Fsumm_z = Fe_z + Fb_z;

            ///расчет скорости частицы
            V_x = V_x + Fsumm_x * step / m;
            V_y = V_y + Fsumm_y * step / m;
            V_z = V_z + Fsumm_z * step / m;

            ///расчет координат частицы
            X = X + V_x * step + Fsumm_x * 0.5 * step * step / m;
            Y = Y + V_y * step + Fsumm_y * 0.5 * step * step / m;
            Z = Z + V_z * step + Fsumm_z * 0.5 * step * step / m;
            cout << "X: " << X << " Y: " << Y << " Z: " << Z << endl;
            array_x[amount_now] = X;
            array_y[amount_now] = Y;
            array_z[amount_now] = Z;
            amount_now++;
            //zapis("Zapis.txt");///вызов функции записи в файл
        }
    }
};


int main() {

    field A(0.0044,0.588);///шаг алгоритма, время движения частицы
    A.setElectricStrength(9,5,10);///Напряженность поля в проекциях координат X,Y,Z соответственно
    A.setCoord(0,0,0);///Начальные координаты частицы на X,Y,Z соответственно
    A.setInduction(530,530,530);///Индукция поля в проекциях координат X,Y,Z соответственно
    A.setSpeed(5000000,5000000,5000000);///Начальная скорость частицы на X,Y,Z соответственно
    A.odnorodnoe();
    A.print();
    
    
    return 0;
}
