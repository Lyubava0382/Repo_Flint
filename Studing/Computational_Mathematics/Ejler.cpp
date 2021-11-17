#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define PI 3.14159265
#define wB 175881 * pow(10,3)

class DrawLines{
public:
    //Подаются на вход массивы с данными, которые нужно отобразить и их размер N.
    void print(int N, float *array_x,float *array_y,float *array_z) {
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

        VertexArray linesX(sf::LineStrip, N);
        VertexArray linesY(sf::LineStrip, N);
        VertexArray linesZ(sf::LineStrip, N);

        float size_gr = 0.00008; //Масштаб
        double step_gr = (W-100)/N;
        double t = 0.0;
        for (int i = 0; i < N; i++) {
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
};

//Класс для формирования данных для отрисовки: метод Эйлера, Хьюна и аналитический метод
class MoveElectron{
    DrawLines* drawer;
    float B, V_0, degree, x_0,y_0,z_0;
    float w;
    float *array_x, *array_y, *array_z;
public:
    MoveElectron(float B_ = 1.2, float V_0_ = 2000000,
                 float degree_ = 45 * PI/180, float x_0_ = 0,float y_0_ = 0,
                 float z_0_ = 0):B(B_),V_0(V_0_),degree(degree_),
                 x_0(x_0_),y_0(y_0_),z_0(z_0_){
        w = wB*B;
        drawer = new DrawLines;
    };
    void EjlerMethod(int N,float time){
        array_x = new float[N];
        array_y = new float[N];
        array_z = new float[N];
        float step = time/N;
        float x = x_0, y = y_0,z = z_0;
        std::ofstream file;
        file.open("./logs/logsEjler");
        int amount_now = 0;
        for(float cur_time = step;cur_time < time;cur_time+=step){
            x = (x + V_0*step*sin(degree)*cos(w*cur_time));
            y = (y + V_0*step*sin(degree)*sin(w*cur_time));
            z = (V_0*cur_time*cos(degree));
            file << x << "   " << y << "   " << z << "\n";
            array_x[amount_now] = x;
            array_y[amount_now] = y;
            array_z[amount_now] = z;
            amount_now++;
        }
        drawer->print(N,array_x,array_y,array_z);
        delete [] array_x, delete [] array_y,delete [] array_z;
        file.close();
    }
    void HyunMethod(int N,float time){
        array_x = new float[N];
        array_y = new float[N];
        array_z = new float[N];
        float step = time/N;
        float x = x_0, y = y_0,z = z_0;
        std::ofstream file;
        file.open("./logs/HyunMethod");
        int amount_now = 0;
        for(float cur_time = step;cur_time < time;cur_time+=step){
            x = x + step/2*(x+V_0*sin(degree)*cos(w*cur_time+step));
            y = y + step/2*(y+V_0*sin(degree)*sin(w*cur_time+step));
            z = V_0*cur_time*cos(degree);
            file << x << "   " << y << "   " << z << "\n";
            array_x[amount_now] = x;
            array_y[amount_now] = y;
            array_z[amount_now] = z;
            amount_now++;
        }
        drawer->print(N,array_x,array_y,array_z);
        delete [] array_x, delete [] array_y,delete [] array_z;
        file.close();
    }
    void AnaliticMethod(int N,float time){
        array_x = new float[N];
        array_y = new float[N];
        array_z = new float[N];
        float step = time/N;
        float x = x_0, y = y_0,z = z_0;
        std::ofstream file;
        file.open("./logs/logsAnalytic");
        int amount_now = 0;
        for(float cur_time = step;cur_time < time;cur_time+=step){
            x = (V_0*sin(degree)*sin(w*cur_time)/w);
            y = (V_0*sin(degree)/w * (1-cos(w*cur_time)));
            z = (V_0*cur_time*cos(degree));
            file << x << "   " << y << "   " << z << "\n";
            array_x[amount_now] = x;
            array_y[amount_now] = y;
            array_z[amount_now] = z;
            amount_now++;
        }
        drawer->print(N,array_x,array_y,array_z);
        delete [] array_x, delete [] array_y,delete [] array_z;
        file.close();
    }
    ~MoveElectron(){
        delete drawer;
    }
};


int main(){
    MoveElectron el;
    //el.EjlerMethod(200,0.00000025);
    el.HyunMethod(200,0.00000025);
    //el.AnaliticMethod(200,0.00000025);
    return 0;
}

//MoveElectron el(100,0.00000025); - хорошие значения для метода Эйлера
